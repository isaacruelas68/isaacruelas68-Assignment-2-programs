#include "Organism.h"
#include<iostream>
#include"Ant.h"

Organism::Organism()
{

}

void Organism::breed(Organism* b[][20], char c[][20], int currX, int currY)
{

}
void Organism:: starve(Organism* s[][20], char c[][20], int currX, int currY, int food)
{

}
int Organism::getFood()
{
	return food;
}
void Organism::move(Organism* g[][20], char c[][20], int direction, int currX, int currY)
{
	

	switch (direction)
	{
		case 0://West

			
				if (g[currX][currY - 1]->getChar() =='X' )//do not move
				{
					
				}

				if (currX < 0 || currX>19 || currY < 0 || currY>19)//if the dB goes out of bounds
				{
					
				}

				else//moves the doodlebug to the new place
				{
					g[currX][currY - 1] = this;
					c[currX][currY - 1] = this->getChar();
					g[currX][currY] = nullptr;
					c[currX][currY] = ' ';
				}

			
			break;

		case 1://North

				if (g[currX - 1][currY]->getChar() == 'X')//does not move
				{
				}

				if (currX < 0 || currX>19 || currY < 0 || currY>19)//if the dB goes out of bounds
				{
					g[currX][currY];
				}

				else
				{
					g[currX - 1][currY] = this;
					c[currX - 1][currY] = this->getChar();
					g[currX][currY] = nullptr;
					c[currX][currY] = ' ';
				}

			
			break;

		case 2://East

			
				if (g[currX][currY + 1]->getChar() =='X')//does not move
				{
				}

				if (currX < 0 || currX>19 || currY < 0 || currY>19)//if the dB goes out of bounds
				{
					g[currX][currY];
				}

				else
				{
					g[currX][currY + 1] = this;
					c[currX][currY + 1] = this->getChar();
					g[currX][currY] = nullptr;
					c[currX][currY] = ' ';
				}

			
			break;

		case 3://South
			
				if (g[currX + 1][currY]->getChar() == 'X')//does not move
				{
				}

				if (currX < 0 || currX>19 || currY < 0 || currY>19)//if the dB goes out of bounds
				{
					g[currX][currY];
				}

				else
				{
					g[currX + 1][currY] = this;
					c[currX + 1][currY] = this->getChar();
					g[currX][currY] = nullptr;
					c[currX][currY] = ' ';
				}

			
			break;



		default:
			std::cout << "were not able to input";
	}
}

char Organism::getChar()
{
	return 'l';

}
bool Organism::hasMoved()
{
	return true;
}
void Organism::die(Organism* d[][20],int currX, int currY,int direction)
{


}
//char* Organism::getnull()
//{
//	return null;
//}