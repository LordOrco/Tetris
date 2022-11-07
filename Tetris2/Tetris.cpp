// Tetris.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Tetris.h"
using namespace std;

void Tetris::ProcessKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada " << key << endl;
	if ((clock() - moveTimer) >= 100) {
		moveTimer = clock();
		switch (key) {
		case 'w':
			girarPieza();
			break;
		case 'a':
			moverPieza(-1);
			break;
		case 's':
			gestionBajada();
			break;
		case 'd':
			moverPieza(1);
			break;
		}
	}
	if (key == 'q' && (clock() - dropTimer) >= 400) {
		dropTimer = clock();

		while (tablero.puedeBajar(pieza)) {
			tablero.bajarPieza(pieza);
		}
		tablero.bloquearPieza(pieza);
		tablero.vaciarFilas();
		piezaSinColocar = false;
	}
	if (key == 'c') {
		if (!hayReserva) {
			tablero.eliminarPieza(pieza);
			hayReserva = true;
			piezaCambiada = true;

			reserva = Pieza(pieza.tipo);
			pieza = Pieza(piezas[0].tipo);
			piezas[0] = Pieza(piezas[1].tipo);
			piezas[1] = Pieza(piezas[2].tipo);
			piezas[2] = Pieza(piezas[3].tipo);
			piezas[3] = Pieza(rand() % 7 + 1);

			tablero.nuevaPieza(pieza);
			//printGame();

		}
		if (hayReserva && !piezaCambiada) {
			tablero.eliminarPieza(pieza);
			piezaCambiada = true;

			Pieza aux = Pieza(pieza.tipo);
			pieza = Pieza(reserva.tipo);
			reserva = aux;

			tablero.nuevaPieza(pieza);
			//printGame();
		}
	}
	if (key == 'x') {
		cout << "??";
	}
}

void Tetris::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del raton " << x << ", " << y << endl;
}

void Tetris::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Click:  " << button << endl;
	cout << prueba.GetVer1().GetX() << ", " << prueba.GetVer3().GetX() << endl;
	if (state == 1 && 
		10 <= x && x <= 110 &&
		20 <= y && y <= 60) {
		prueba.pressed();
		pause = !pause;
	}
}

void Tetris::Init() {
	tablero.Init();
	tableroGUI.Init();
	piezaReserva.Init();
	pieza1.Init();
	pieza2.Init();
	pieza3.Init();
	pieza4.Init();
}

void Tetris::Render() {
	prueba.Render();
	tableroGUI.Update(tablero);
	piezaReserva.Update(reserva);
	pieza1.Update(piezas[0]);
	pieza2.Update(piezas[1]);
	pieza3.Update(piezas[2]);
	pieza4.Update(piezas[3]);
}

void Tetris::Update() {
	if (tablero.puedeNuevaPieza(pieza) && !pause) {

		if (!piezaSinColocar && tablero.puedeNuevaPieza(pieza)) {
			pieza = Pieza(piezas[0].tipo);
			piezas[0] = piezas[1];
			piezas[1] = piezas[2];
			piezas[2] = piezas[3];
			piezas[3] = Pieza(rand() % 7 + 1);

			tablero.nuevaPieza(pieza);
			piezaSinColocar = true;
			piezaCambiada = false;
			comprobarNivel();

			//printGame();
		}

		if ((clock() - timer) >= tiempoPP) {
			timer = clock();
			gestionBajada();
		}

	}
	else if(!pause) {
		glutLeaveMainLoop();
	}
	Render();
}

void Tetris::comprobarNivel() {
	if (tablero.filasDestruidas - filasDestruidas >= 5 && tiempoPP >= 100) {
		subirNivel();
		filasDestruidas = tablero.filasDestruidas;
	}
}

void Tetris::gestionBajada() {
	if (tablero.puedeBajar(pieza)) {
		tablero.bajarPieza(pieza);
		pieza.fila++;
	}
	else {
		tablero.bloquearPieza(pieza);
		tablero.vaciarFilas();
		piezaSinColocar = false;
	}
	//printGame();
}

void Tetris::moverPieza(int dir) {
	if (tablero.puedeMoverPieza(pieza, dir)) {
		tablero.moverPieza(pieza, dir);
		pieza.columna += dir;
		//printGame();
	}
}

void Tetris::girarPieza() {
	tablero.girarPieza(pieza);
	//printGame();
}


void Tetris::subirNivel() {
	tiempoPP -= 50;
	nivel++;
}

/*
void Tetris::printGame() {
	system("CLS");
	printReserva(reserva);
	tablero.printTablero();
	printPiezasSiguientes(piezas);
}

void Tetris::printReserva(Pieza reserva) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (reserva.pieza[i][j] == 0) {
				SetConsoleTextAttribute(pieza.h, 8);
				cout cuadrado;
			}
			else if (reserva.pieza[i][j] == 1) {
				SetConsoleTextAttribute(pieza.h, 4);
				cout cuadrado;
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void Tetris::printPiezasSiguientes(Pieza piezas[]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 16; j++) {
			if (i < 4) {
				if (piezas[j / 4].pieza[i][j % 4] == 0) {
					SetConsoleTextAttribute(pieza.h, 8);
					cout cuadrado;
				}
				else if (piezas[j / 4].pieza[i][j % 4] == 1) {
					SetConsoleTextAttribute(pieza.h, 4);
					cout cuadrado;
				}
				if (j == 3 || j == 7 || j == 11) {
					cout << " ";
				}
			}
		}
		cout << "\n";
	}
	cout << "\n";
}
*/

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
