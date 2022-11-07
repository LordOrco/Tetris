#pragma once
#include "Tetris.h"
#include "MainMenu.h"

class GameManager {
private:
	Tetris game;
	MainMenu menuPrincipal;

	bool playing;
public:

	GameManager() :
		menuPrincipal(),
		game(),

		playing(false)
	{}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	void Exit();
};