#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "Pieza.h"
#define cuadrado <<(char)178 <<(char)178

class Tablero {
public:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int filasDestruidas;
	const int filas;
	const int columnas;
	int tablero[22][12];

	Tablero() :
		filasDestruidas(0),
		filas(22),
		columnas(12),
		tablero{}
	{	}

	void Init();
	bool puedeNuevaPieza(Pieza pieza);
	void nuevaPieza(Pieza& pieza);
	bool puedeBajar(Pieza pieza);
	void bajarPieza(Pieza pieza);
	void bloquearPieza(Pieza pieza);
	bool puedeMoverPieza(Pieza pieza, int dir);
	void moverPieza(Pieza pieza, int dir);
	bool puedeGirar(Pieza pieza, int dist);
	void girarPieza(Pieza& pieza);
	void eliminarPieza(Pieza pieza);
	void eliminarFila(int fila);
	void bajarColocadas(int fila);
	void vaciarFilas();
	void printTablero();
	Tablero operator=(Tablero otro);
};