#pragma once
#include "GL/glut.h"
#include "Vector3D.h"
#include "Color.h"

class Text
{
private:
	unsigned char* string;
	Color color;
	Vector3D position;

public:
	

	Text():
		string( (unsigned char*) "The quick god jumps over the lazy brown fox."),
		color(0.0f, 0.0f, 0.0f),
		position(Vector3D(0,0,0))
	{}

	Text(unsigned char* pString, Vector3D pPosition) :
		string((unsigned char*) pString),
		color(0.0f, 0.0f, 0.0f),
		position(pPosition)
	{}

	inline Vector3D GetPosition() { return this->position; }
	inline Color GetColor() { return this->color; }
	inline unsigned char* GetString() { return this->string; }

	inline void SetPosition(Vector3D& positionToSet) { this->position = positionToSet; }
	inline void SetColor(Color& colorToSet) { this->color = colorToSet; }
	inline void SetString(unsigned char* stringToSet) { this->string = stringToSet; }
	
	void Render();
};

