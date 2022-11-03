#pragma once
#include "Vector3D.h"
#include "GL/glut.h"
class Cuadrado
{
public:
	Vector3D ver1;
	Vector3D ver2;
	Vector3D ver3;
	Vector3D ver4;

	float redComponent = 0;
	float greenComponent = 0;
	float blueComponent = 0;

	Cuadrado(){}

	Cuadrado(Vector3D ver1, Vector3D ver2, Vector3D ver3, Vector3D ver4, float redComponent, float greenComponent, float blueComponent):
		redComponent(redComponent),
		greenComponent(greenComponent),
		blueComponent(blueComponent),
		ver1(ver1),
		ver2(ver2),
		ver3(ver3),
		ver4(ver4)
	{}

	void Render();

};

