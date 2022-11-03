#pragma once
#include <GL/glut.h>
#include "Cuadrado.h"
#include "Tablero.h"
#include <stdlib.h>

class Grid
{
public:
	Cuadrado** matriz;

	Vector3D coordinates;

	int filas = 0;	
	int columnas = 0;

	Grid(Vector3D pCoordinates) :
		matriz{},
		filas(20),
		columnas(10),
		coordinates(pCoordinates)
	{}

	Grid(Vector3D pcoordinates, Pieza ppieza) :
		matriz{},
		coordinates(pcoordinates),
		filas(4),
		columnas(4)
	{}

	void Init();
	void Render();
	void Update(Tablero tablero);
	void Update(Pieza pieza);
};

