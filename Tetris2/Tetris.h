#pragma once
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Tablero.h"
#include "Grid.h"
#include "Button.h"
#include "GL/freeglut.h"

using namespace std;


class Tetris {
public:
	Button pausa;
	Button salir;
	Text score;

	Grid tableroGUI;
	Grid piezaReserva;
	Grid pieza1;
	Grid pieza2;
	Grid pieza3;
	Grid pieza4;

	int filasDestruidas;
	int  nivel;
	int tiempoPP;
		
	Tablero tablero;
	Pieza pieza;
	Pieza reserva;
	Pieza piezas[4];

	bool piezaSinColocar;
	bool pause;
	bool perder;
	bool exitGame;
	bool piezaCambiada;
	bool hayReserva;
	
	clock_t timer = clock(); // depende del nivel
	clock_t moveTimer = clock(); //100ms
	clock_t dropTimer = clock(); //400ms

	Tetris() :
		filasDestruidas(0),
		nivel(0),
		tiempoPP(1000),
		reserva(0),
		piezas{},

		piezaSinColocar(false),
		piezaCambiada(false),
		hayReserva(false),
		pause(false),
		perder(false),
		exitGame(false),

		pieza1(Vector3D(-10, -11, 0), piezas[0]),
		pieza2(Vector3D(-5, -11, 0), piezas[1]),
		pieza3(Vector3D(0, -11, 0), piezas[2]),
		pieza4(Vector3D(5, -11, 0), piezas[3]),
		piezaReserva(Vector3D(-5, 15, 0), reserva),
		tableroGUI(Vector3D(-5, 10, 0)),

		pausa(Vector3D(-12, 14, 0), 5, 2, Color(1, 1, 1), string("Pause")),
		salir(Vector3D(-12, 11, 0), 5, 2, Color(1, 1, 1), string("Salir")),
		score(string("Puntos: 0"), Vector3D(0, 11, 0))

	{
		for (int i = 0; i < 4; i++) {
			piezas[i] = Pieza(rand() % 7 + 1);
		}
	}


	void comprobarNivel();
	//void printReserva(Pieza reserva);
	//void printPiezasSiguientes(Pieza piezas[]);
	//void printGame();
	void gestionBajada();
	void moverPieza(int dir);
	void girarPieza();
	void subirNivel();
	void exit();

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};