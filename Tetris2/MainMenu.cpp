#include "MainMenu.h"

void MainMenu::ProcessMouseClick(int button, int state, int x, int y) {
	if (state == 1 &&
		150 <= x && x <= 350 &&
		200 <= y && y <= 300) {
		jugar.pressed();
	}
	if (state == 1 &&
		150 <= x && x <= 350 &&
		350 <= y && y <= 450) {
		salir.pressed();
	}
}

void MainMenu::Render() {
	jugar.Render();
	salir.Render();
	titulo.Render();
	lastScore.Render();
}
