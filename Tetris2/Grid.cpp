#include "Grid.h"

void Grid::Init() {

	matriz = new Cuadrado * [filas];

	for (int i = 0; i < filas; i++) {
		matriz[i] = new Cuadrado[columnas];
	}

	float coordY = coordinates.GetY();
	for (int i = 0; i < filas; i++) {
		float coordX = coordinates.GetX();
		for (int j = 0; j < columnas; j++) {
			matriz[i][j].ver1.SetX(coordX);
			matriz[i][j].ver2.SetX(coordX+1);
			matriz[i][j].ver3.SetX(coordX+1);
			matriz[i][j].ver4.SetX(coordX);

			matriz[i][j].ver1.SetY(coordY);
			matriz[i][j].ver2.SetY(coordY);
			matriz[i][j].ver3.SetY(coordY - 1);
			matriz[i][j].ver4.SetY(coordY - 1);

			matriz[i][j].ver1.SetZ(coordinates.GetZ());
			matriz[i][j].ver2.SetZ(coordinates.GetZ());
			matriz[i][j].ver3.SetZ(coordinates.GetZ());
			matriz[i][j].ver4.SetZ(coordinates.GetZ());

			matriz[i][j].redComponent = 0.5;
			matriz[i][j].greenComponent = 0.5;
			matriz[i][j].blueComponent = 0.5;

			coordX++;
		}
		coordY--;
	}
}

void Grid::Render() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			matriz[i][j].Render();
		}
	}
}

void Grid::Update(Tablero tablero) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (tablero.tablero[i + 1][j + 1] == 0) {
				matriz[i][j].redComponent = 0;
				matriz[i][j].greenComponent = 0;
				matriz[i][j].blueComponent = 0;
			}
			else if (tablero.tablero[i + 1][j + 1] == 1) {
				matriz[i][j].redComponent = 1;
				matriz[i][j].greenComponent = 0;
				matriz[i][j].blueComponent = 0;
			}
			else if (tablero.tablero[i + 1][j + 1] == 2) {
				matriz[i][j].redComponent = 0.5;
				matriz[i][j].greenComponent = 0.5;
				matriz[i][j].blueComponent = 0.5;
			}
		}
	}
	Render();
}

void Grid::Update(Pieza pieza) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (pieza.pieza[i][j] == 0) {
				matriz[i][j].redComponent = 0;
				matriz[i][j].greenComponent = 0;
				matriz[i][j].blueComponent = 0;
			}
			else if (pieza.pieza[i][j] == 1) {
				matriz[i][j].redComponent = 1;
				matriz[i][j].greenComponent = 0;
				matriz[i][j].blueComponent = 0;
			}
		}
	}
	Render();
}
