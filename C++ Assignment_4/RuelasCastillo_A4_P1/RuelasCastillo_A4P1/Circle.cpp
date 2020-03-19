#include "Circle.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
Circle::Circle():Shape()
{
	radius = 1;
}
Circle::Circle(int radius):Shape()
{
	this->radius = radius;
}
void Circle::draw()
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
	}
	glEnd();
}
void Circle::updateCoordinates()
{
	Shape::updateCoordinates();

}