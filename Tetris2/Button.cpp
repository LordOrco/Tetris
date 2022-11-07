#include "Button.h"

void Button::pressed() {
	cout << "Has pulsado el boton";
	SetIsPressed(!GetIsPressed());
}

void Button::Render() {
	glColor3f(color.GetRedComponent(), color.GetGreenComponent(), color.GetBlueComponent());
	glBegin(GL_POLYGON);
	glVertex3f(ver1.GetX(), ver1.GetY(), ver1.GetZ());
	glVertex3f(ver2.GetX(), ver2.GetY(), ver2.GetZ());
	glVertex3f(ver3.GetX(), ver3.GetY(), ver3.GetZ());
	glVertex3f(ver4.GetX(), ver4.GetY(), ver4.GetZ());
	glEnd();

	texto.Render();
}