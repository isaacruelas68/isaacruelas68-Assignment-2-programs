#include "Ant.h"
#include <iostream>
#include <typeinfo>
#include"Organism.h"
#include"DoodleBug.h"
#include<typeinfo>
void Ant::breed(Organism* b[][20], char c[][20], int currX, int currY)
{


	if (b[currX][currY - 1] == nullptr)//west
	{
		Ant* ant = new Ant();
		b[currX][currY - 1] = ant;
		c[currX][currY - 1] = 'O';
		return;
	}

	if (b[currX - 1][currY] == nullptr)//north
	{
		Ant* ant = new Ant();
		b[currX - 1][currY] = ant;
		c[currX - 1][currY] = 'O';
		return;
	}
	if (b[currX][currY + 1] == nullptr)//east
	{
		Ant* ant = new Ant();
		b[currX][currY + 1] = ant;
		c[currX][currY + 1] = 'O';
		return;
	}
	if (b[currX + 1][currY] == nullptr)//south
	{
		Ant* ant = new Ant();
		b[currX + 1][currY] = ant;
		c[currX + 1][currY] = 'O';
		return;
	}
	else
		return;

}
void Ant::move(Organism* g[][20], char c[][20], int direction, int currX, int currY)
{

		switch (direction)
		{
		case 0://West


			if (g[currX][currY - 1] == nullptr)
			{
				g[currX][currY - 1] = this;
				c[currX][currY - 1] = this->o;
				g[currX][currY] = nullptr;
				c[currX][currY] = ' ';
			}


			break;

		case 1://North


			if (g[currX - 1][currY] == nullptr)
			{
				g[currX - 1][currY] = this;
				c[currX - 1][currY] = this->o;
				g[currX][currY] = nullptr;
				c[currX][currY] = ' ';
			}
			break;

		case 2://East



			if (g[currX][currY + 1] == nullptr)
			{
				g[currX][currY + 1] = this;
				c[currX][currY + 1] = this->o;
				g[currX][currY] = nullptr;
				c[currX][currY] = ' ';
			}


			break;

		case 3://South



			if (g[currX + 1][currY] == nullptr)
			{

				g[currX + 1][currY] = this;
				c[currX + 1][currY] = this->o;
				g[currX][currY] = nullptr;
				c[currX][currY] = ' ';
			}
			break;



		default:
			std::cout << "were not able to input";
		}
	
}
char Ant::getChar()
{
	return o;
}
void Ant::die(Organism* d[][20], int currX, int currY, int direction)
{


}
bool Ant::hasMoved()
{
	return true;
}
char Ant::getO()
{
	return o;
}