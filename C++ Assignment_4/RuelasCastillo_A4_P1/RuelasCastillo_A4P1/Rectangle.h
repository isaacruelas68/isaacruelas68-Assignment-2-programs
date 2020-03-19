#pragma once
#include "Shape.h"
class Rectangle :public Shape
{
public:
	Rectangle();
	Rectangle(int diameter);
	void draw();
	void updateCoordinates();
};

