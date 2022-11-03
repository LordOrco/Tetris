#include "Pieza.h"

using namespace std;

void Pieza::girarPieza() {
	int temp = alto;
	alto = ancho;
	ancho = temp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			piezaGirada[i][j] = pieza[4 - j - 1][i];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pieza[i][j] = piezaGirada[i][j];
		}
	}
}

int Pieza::buscarIndiceI() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (pieza[i][j] == 1) {
				return i;
			}
		}
	}
}

int Pieza::buscarIndiceJ() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (pieza[i][j] == 1) {
				return j;
			}
		}
	}
}

void Pieza::printPieza() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (pieza[i][j] == 0) {
				SetConsoleTextAttribute(h, 8);
				cout << "[0]";
			}
			else if (pieza[i][j] == 1) {
				SetConsoleTextAttribute(h, 4);
				cout << "[1]";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

