#include "ColorCircle.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
ColorCircle::ColorCircle():Shape()
{
	radius = 1;
}
ColorCircle::ColorCircle(int radius):Shape()
{
	this->radius = radius;
}
void ColorCircle::draw()
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius * 2.0 / 3, y + cos(angle) * radius * 2.0 / 3);
	}
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius * 1.0 / 3, y + cos(angle) * radius * 1.0 / 3);
	}
	glEnd();
}
void ColorCircle::updateCoordinates()
{
	Shape::updateCoordinates();

}