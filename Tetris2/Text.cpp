#include "Text.h"

void Text::Render() {
	glColor3f(color.GetRedComponent(), color.GetGreenComponent(), color.GetBlueComponent());
	glRasterPos3f(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	int len = strlen((const char*)string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (unsigned char)string[i]);
	}
}