#include "Tablero.h"

using namespace std;


void Tablero::Init() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (j == 0 || j == columnas - 1 || i == 0 || i == filas - 1) {
				tablero[i][j] = 2;
			}
			else {
				tablero[i][j] = 0;
			}
		}
	}
}

bool Tablero::puedeNuevaPieza(Pieza pieza) {
	for (int i = 1; i < pieza.alto + 1; i++) {
		for (int j = 0; j < pieza.ancho; j++) {
			if (tablero[i][j + (columnas - pieza.ancho) / 2] == 2) {
				return false;
			}
		}
	}
	return true;
}


void Tablero::nuevaPieza(Pieza& pieza) {
	for (int i = pieza.fila; i < pieza.fila + 4; i++) {
		for (int j = pieza.columna; j < pieza.columna + 4; j++) {
			if (pieza.pieza[(i - pieza.fila)][j - pieza.columna] == 1) {
				tablero[i][j] = 1;
			}
		}
	}
}


bool Tablero::puedeBajar(Pieza pieza) {
	for (int i = filas-1; i >= 0; i--) {
		for (int j = columnas-1; j >= 0; j--) {
			if (tablero[i][j] == 1) {
				if (tablero[i + 1][j] == 2) {
					return false;
				}

			}
		}
	}
	return true;
}

void Tablero::bajarPieza(Pieza pieza) {
	for (int i = filas-1; i >= 0; i--) {
		for (int j = columnas-1; j >= 0; j--) {
			if (tablero[i][j] == 1) {
				tablero[i][j] = 0;
				tablero[i + 1][j] = 1;
			}
		}
	}
}

void Tablero::bloquearPieza(Pieza pieza) {
	for (int i = filas-1; i >= 0; i--) {
		for (int j = columnas - 1; j > 0; j--) {
			if (tablero[i][j] == 1) {
				tablero[i][j] = 2;
			}
		}
	}
}

bool Tablero::puedeMoverPieza(Pieza pieza, int dir) {
	for (int i = filas-1; i > 0; i--) {
		if (dir == 1) {
			for (int j = columnas-1; j > 0; j--) {
				if (tablero[i][j] == 1) {
					if (tablero[i][j + 1] == 2) {
						return false;
					}
				}
			}
		}
		else {
			for (int j = 1; j < columnas-1; j++) {
				if (tablero[i][j] == 1) {
					if (tablero[i][j - 1] == 2) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

void Tablero::moverPieza(Pieza pieza, int dir) {
	for (int i = filas-1; i >= 0; i--) {
		if (dir == 1) {
			for (int j = columnas - 1; j > 0; j--) {
				if (tablero[i][j] == 1) {
					tablero[i][j] = 0;
					tablero[i][j + 1] = 1;
				}
			}
		}
		else {
			for (int j = 1; j < columnas - 1; j++) {
				if (tablero[i][j] == 1) {
					tablero[i][j] = 0;
					tablero[i][j - 1] = 1;
				}
			}
		}
	}
}

bool Tablero::puedeGirar(Pieza pieza, int dist) {
	pieza.girarPieza();
	for (int i = pieza.fila; i < pieza.fila + 4; i++) {
		for (int j = pieza.columna; j < pieza.columna + 4; j++) {
			if (pieza.pieza[i - pieza.fila][j - pieza.columna] == 1 &&
				tablero[i][j + dist] == 2) {
				return false;
			}
		}
	}
	return true;
}

void Tablero::eliminarPieza(Pieza pieza) {
	for (int i = filas-1; i >= 0; i--) {
		for (int j = columnas - 1; j > 0; j--) {
			if (tablero[i][j] == 1) {
				tablero[i][j] = 0;
			}
		}
	}
}

void Tablero::girarPieza(Pieza& pieza) {
	for (int i = filas-1; i >= 0; i--) {
		for (int j = columnas - 1; j > 0; j--) {
			if (tablero[i][j] == 1) {
				tablero[i][j] = 0;
			}
		}
	}
		if (puedeGirar(pieza, 0)) {
			pieza.girarPieza();
			nuevaPieza(pieza);
		}
		else if (puedeGirar(pieza, 1)) {
			pieza.columna++;
			pieza.girarPieza();
			nuevaPieza(pieza);
		}
		else if (puedeGirar(pieza, -1)) {
			pieza.columna--;
			pieza.girarPieza();
			nuevaPieza(pieza);
		}
		else if (puedeGirar(pieza, 2)) {
			pieza.columna += 2;
			pieza.girarPieza();
			nuevaPieza(pieza);
		}
		else if (puedeGirar(pieza, -2)) {
			pieza.columna -= 2;
			pieza.girarPieza();
			nuevaPieza(pieza);
		}
		else if (puedeGirar(pieza, 3)) {
			pieza.columna += 3;
			pieza.girarPieza();
			nuevaPieza(pieza);
		}
		else if (puedeGirar(pieza, -3)) {
			pieza.columna -= 3;
			pieza.girarPieza();
			nuevaPieza(pieza);
		}
		else {
			nuevaPieza(pieza);
		}

}

void Tablero::eliminarFila(int fila) {
	for (int i = 1; i < columnas - 1; i++) {
		tablero[fila][i] = 0;
	}
}

void Tablero::bajarColocadas(int fila) {
	for (int i = fila; i > 0; i--) {
		for (int j = 1; j < columnas - 1; j++) {
			if (tablero[i][j] == 2) {
				if (tablero[i + 1][j] != 2) {
					tablero[i][j] = 0;
					tablero[i + 1][j] = 2;
				}
			}
		}
	}
}

void Tablero::vaciarFilas() {
	for (int i = 1; i < filas - 1; i++) {
		int rellenas = 0;
		for (int j = 1; j < columnas - 1; j++) {
			if (tablero[i][j] == 2) {
				rellenas++;
			}
		}
		if (rellenas == 10) {
			filasDestruidas++;
			eliminarFila(i);
			bajarColocadas(i);
		}
	}
}

void Tablero::printTablero() {
	cout << "Filas destruidas: " << filasDestruidas << endl;
	for (int i = 1; i < filas-1; i++) {
		for (int j = 1; j < columnas-1; j++) {
			if (tablero[i][j] == 0) {
				SetConsoleTextAttribute(h, 8);
				cout cuadrado;
			}
			else if (tablero[i][j] == 1) {
				SetConsoleTextAttribute(h, 4);
				cout cuadrado;
			}
			else if (tablero[i][j] == 2) {
				SetConsoleTextAttribute(h, 15);
				cout cuadrado;
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

Tablero Tablero::operator=(Tablero otro) {
	Tablero tableroToReturn;

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			tableroToReturn.tablero[i][j] = otro.tablero[i][j];
		}
	}
	return tableroToReturn;
}