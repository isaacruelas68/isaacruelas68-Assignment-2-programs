#pragma once

class Shape
{
protected:
	static const int WIDTH = 720;
	static const int HEIGHT = 480;
	float x;
	float y;
	float deltaX;
	float deltaY;
	int type;		// Identifies type of shape being stored.  See list below.
	int radius;		// If its a circle this is the radius
	int diameter;	// If its a square this is the diameter
public:
	 Shape();
	~Shape();
	virtual void draw()=0;
	virtual void updateCoordinates()=0;
	/*friend class Rectangle;///this is an optional route to use instead of changing the variables from private to protected...
	friend class Circle;
	friend class ColorCircle;*/
};
