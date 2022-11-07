#pragma once
#include "GL/glut.h"
#include "Vector3D.h"
#include "Color.h"
#include <string>

class Text
{
private:
	string text;
	Color color;
	Vector3D position;

public:
	

	Text():
		text("The quick god jumps over the lazy brown fox."),
		color(0.0f, 0.0f, 0.0f),
		position(Vector3D(0,0,0))
	{}

	Text(string pString, Vector3D pPosition) :
		text(pString),
		color(0.0f, 0.0f, 0.0f),
		position(pPosition)
	{}

	inline Vector3D GetPosition() { return this->position; }
	inline Color GetColor() { return this->color; }
	inline string GetString() { return this->text; }

	inline void SetPosition(Vector3D& positionToSet) { this->position = positionToSet; }
	inline void SetColor(Color& colorToSet) { this->color = colorToSet; }
	inline void SetString(string stringToSet) { this->text = stringToSet; }
	
	void Render();
};

