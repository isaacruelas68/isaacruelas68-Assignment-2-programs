#include "Rectangle.h"
#include "Shape.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
Rectangle::Rectangle()
{
	diameter = 1;
}
Rectangle::Rectangle(int diameter):Shape()
{
	this->diameter = diameter;
}
void Rectangle::draw()
{
	glColor3f(1, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(x - (diameter / 2), y - (diameter / 2));
	glVertex2f(x + (diameter / 2), y - (diameter / 2));
	glVertex2f(x + (diameter / 2), y + (diameter / 2));
	glVertex2f(x - (diameter / 2), y + (diameter / 2));
	glEnd();
}
void Rectangle::updateCoordinates()
{
	Shape::updateCoordinates();

}