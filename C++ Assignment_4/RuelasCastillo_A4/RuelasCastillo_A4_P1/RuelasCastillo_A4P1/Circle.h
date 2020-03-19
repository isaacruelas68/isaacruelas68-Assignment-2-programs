#pragma once
#include "Shape.h"
class Circle :public Shape
{
public: 
	Circle();
	Circle(int radius);
	 void draw();
	 void updateCoordinates();

};

