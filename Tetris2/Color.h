#pragma once
#include <iostream>
class Color
{
private:
	float redComponent;
	float greenComponent;
	float blueComponent;

public:

	Color() :
		redComponent(0),
		greenComponent(0),
		blueComponent(0) {}

	Color(float redComponentToSet, float greenComponentToSet, float blueComponentToSet) :
		redComponent(redComponentToSet),
		greenComponent(greenComponentToSet),
		blueComponent(blueComponentToSet) {}

	inline float GetRedComponent() const { return this->redComponent; }
	inline float GetGreenComponent() const { return this->greenComponent; }
	inline float GetBlueComponent() const { return this->blueComponent; }

	void SetRedComponent(const float& redComponentToSet);
	void SetGreenComponent(const float& greenComponentToSet);
	void SetBlueComponent(const float& blueComponentToSet);

	float clamp(float floatToClamp);
};

