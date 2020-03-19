#pragma once
#include "Shape.h"
class ColorCircle :public Shape
{
public:
	ColorCircle();
	ColorCircle(int radius);
	void draw();
	void updateCoordinates();
};

