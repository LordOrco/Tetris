#include "GameManager.h"


void GameManager::ProcessKeyPressed(unsigned char key, int px, int py) {
	cout << "Se ha pusado la tecla " << key << endl;
	if (playing) {
		game.ProcessKeyPressed(key, px, py);
	}
}

void GameManager::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del raton " << x << ", " << y << endl;
}

void GameManager::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Click:  " << button << endl;
	if (playing) {
		game.ProcessMouseClick(button, state, x, y);
	}
	else {
		menuPrincipal.ProcessMouseClick(button, state, x, y);
	}
}

void GameManager::Init() {
}

void GameManager::Render() {
	if (playing) {
		game.Render();
	}
	else {
		menuPrincipal.Render();
	}
}

void GameManager::Update() {
	if (!playing) {
		if (menuPrincipal.getJugar().GetIsPressed()) {
			playing = true;
			game.Init();
		}
		if (menuPrincipal.getSalir().GetIsPressed()) {
			Exit();
		}
	}
	if (playing) {
		game.Update();
		if (game.salir.GetIsPressed() && game.perder) {
			playing = false;
			game = Tetris();
			menuPrincipal = MainMenu(game.tablero.filasDestruidas);
			game.tablero.filasDestruidas = 0;
		}
	}
	Render();
}

void GameManager::Exit() {
	glutLeaveMainLoop();
}