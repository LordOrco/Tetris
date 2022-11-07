#pragma once
#include "Vector3D.h"
#include "GL/glut.h"
#include "Color.h"
#include "Text.h"

class Button
{
private:
	Text texto;

	Vector3D position;
	Vector3D ver1;
	Vector3D ver2;
	Vector3D ver3;
	Vector3D ver4;

	Color color;

	float width;
	float height;

	bool isPressed;

public:

	Button(Vector3D pPosition, float pWidth, float pHeight, Color pColor, string pString) :
		texto(pString, Vector3D(pPosition.GetX() + pWidth / 4, pPosition.GetY() - pHeight/2, pPosition.GetZ() + 0.0001)),

		position(pPosition),
		width(pWidth),
		height(pHeight),
		color(pColor),

		ver1(pPosition),
		ver2(ver1.GetX() + pWidth, ver1.GetY(), ver1.GetZ()),
		ver3(ver1.GetX() + pWidth, ver1.GetY() - pHeight, ver1.GetZ()),
		ver4(ver1.GetX(), ver1.GetY() - pHeight, ver1.GetZ()),

		isPressed(false)
	{}

	inline Vector3D GetPosition() { return this->position; }
	inline Vector3D GetVer1() { return this->ver1; }
	inline Vector3D GetVer2() { return this->ver2; }
	inline Vector3D GetVer3() { return this->ver3; }
	inline Vector3D GetVer4() { return this->ver4; }

	inline Color GetColor() { return this->color; }
	inline float GetWidth() { return this->width; }
	inline float GetHeight() { return this->height; }
	inline bool GetIsPressed() { return this->isPressed; }

	inline void SetIsPressed(bool pIsPressed) { this->isPressed = pIsPressed; }


	void Render();
	virtual void pressed();
};

