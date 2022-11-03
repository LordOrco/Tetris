#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

class Pieza {
private:

public:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int fila;
	int columna;

	int tipo;
	int alto;
	int ancho;
	int pieza[4][4];
	int piezaGirada[4][4];
	bool colocada;

	Pieza() :
		tipo(-1),

		fila(0),
		columna(4),

		alto(0),
		ancho(0),
		pieza{},
		piezaGirada{},
		colocada(false)
	{};

	Pieza(int ptipo):
		tipo(ptipo),

		fila(0),
		columna(4),

		alto(0),
		ancho(0),
		pieza{},
		piezaGirada{},
		colocada(false)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				pieza[i][j] = 0;
			}
		}

		switch (tipo) {
		default:
			break;
		case 1:
			alto = 2;
			ancho = 2;
			pieza[1][1] = 1;
			pieza[2][1] = 1;
			pieza[1][2] = 1;
			pieza[2][2] = 1;
			break;
		case 2:
			alto = 1;
			ancho = 4;
			pieza[1][0] = 1;
			pieza[1][1] = 1;
			pieza[1][2] = 1;
			pieza[1][3] = 1;
			break;
		case 3:
			alto = 2;
			ancho = 3;
			pieza[1][0] = 1;
			pieza[1][1] = 1;
			pieza[1][2] = 1;
			pieza[2][2] = 1;
			break;
		case 4:
			alto = 2;
			ancho = 3;
			pieza[1][0] = 1;
			pieza[1][1] = 1;
			pieza[2][1] = 1;
			pieza[2][2] = 1;
			break;
		case 5:
			alto = 2;
			ancho = 3;
			pieza[1][1] = 1;
			pieza[1][2] = 1;
			pieza[1][3] = 1;
			pieza[2][1] = 1;
			break;
		case 6:
			alto = 2;
			ancho = 3;
			pieza[1][2] = 1;
			pieza[1][3] = 1;
			pieza[2][1] = 1;
			pieza[2][2] = 1;
			break;
		case 7:
			alto = 2;
			ancho = 3;
			pieza[1][1] = 1;
			pieza[2][0] = 1;
			pieza[2][1] = 1;
			pieza[2][2] = 1;
			break;
		}
	};
	
	void girarPieza();
	int buscarIndiceI();
	int buscarIndiceJ();
	void printPieza();

};