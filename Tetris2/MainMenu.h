#pragma once
#include "Button.h"

class MainMenu {
private:
	Button jugar;
	Button salir;
	Text titulo;
	Text lastScore;

public:
	
	MainMenu():
		jugar(Vector3D(-5.0f, 5.0f, 0.0f), 10, 5, Color(1.0f, 1.0f, 1.0f), string("Jugar")),
		salir(Vector3D(-5.0f, -2.5f, 0.0f), 10, 5, Color(1.0f, 1.0f, 1.0f), string("Salir")),
		titulo(string("TETRIS"), Vector3D(-1.0f, 7.0f, 7.0f)),
		lastScore(string("¡Dale a \"Jugar\"!"), Vector3D(-3.0f, 7.0f, 0.0f))
	{}

	MainMenu(int pLastScore) :
		jugar(Vector3D(-5.0f, 5.0f, 0.0f), 10, 5, Color(1.0f, 1.0f, 1.0f), string("Jugar")),
		salir(Vector3D(-5.0f, -2.5f, 0.0f), 10, 5, Color(1.0f, 1.0f, 1.0f), string("Salir")),
		titulo(string("TETRIS"), Vector3D(-1.0f, 7.0f, 7.0f)),
		lastScore(string("Ultima puntuacion: ") + to_string(pLastScore), Vector3D(-4.0f, 7.0f, 0.0f))
	{}

	inline Button getJugar() { return this->jugar; }
	inline Button getSalir() { return this->salir; }

	void Render();
	void ProcessMouseClick(int button, int state, int x, int y);
};