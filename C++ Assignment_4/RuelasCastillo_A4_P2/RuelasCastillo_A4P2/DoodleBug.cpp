#include "DoodleBug.h"
#include "Organism.h"
#include<iostream>


void DoodleBug:: breed(Organism* b[][20],char c[][20],int currX,int currY)
{
	

	if (b[currX][currY - 1] == nullptr )//west
	{
		DoodleBug* bug = new DoodleBug();
		b[currX][currY-1] = bug;
		c[currX][currY-1] = 'X';
		return;
	}

	if (b[currX - 1][currY] == nullptr )//north
	{
		DoodleBug* bug = new DoodleBug();
		b[currX-1][currY] = bug;
		c[currX-1][currY] = 'X';
		return;
	}
	if (b[currX][currY + 1] == nullptr )//east
	{
		DoodleBug* bug = new DoodleBug();
		b[currX][currY + 1] = bug;
		c[currX][currY+1] = 'X';
		return;
	}
	if (b[currX + 1][currY] == nullptr )//south
	{
		DoodleBug* bug = new DoodleBug();
		b[currX+1][currY] = bug;
		c[currX+1][currY] = 'X';
		return;
	}
	else
		return;
}

void DoodleBug::starve(Organism* s[][20],char c[][20],int currX,int currY,int food)
{
	
	if (food>=1)
	{
		food = 0;
		return;
	}
	else
	{
		Organism* temp;
		temp = this;// s[currX][currY];
		delete temp;
		s[currX][currY] = nullptr;
		c[currX][currY] = ' ';
	}


}

int DoodleBug::getFood()
{
	return food;
}
void DoodleBug::move(Organism* g[][20], char c[][20], int direction, int currX, int currY)
{
	if (currX < 19 || currX>0 || currY < 19 || currY>0)
	{
		direction = checkAnt(g, c, currX, currY, direction);//checks if ants next door


		switch (direction)
		{
		case 0://West


			if (g[currX][currY - 1] == nullptr)//moves the doodlebug to the new place
			{
				g[currX][currY - 1] = this;
				c[currX][currY - 1] = this->getChar();
				g[currX][currY] = nullptr;
				c[currX][currY] = ' ';
			}
			break;

		case 1://North


			if (g[currX - 1][currY] == nullptr)
			{
				g[currX - 1][currY] = this;
				c[currX - 1][currY] = this->getChar();
				g[currX][currY] = nullptr;
				c[currX][currY] = ' ';
			}
			break;

		case 2://East


			if (g[currX][currY + 1] == nullptr)//does not move
			{
				g[currX][currY + 1] = this;
				c[currX][currY + 1] = this->getChar();
				g[currX][currY] = nullptr;
				c[currX][currY] = ' ';
			}
			break;

		case 3://South

			if (g[currX + 1][currY] == nullptr)//does not move
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
	else
		return;
}

void DoodleBug::die(Organism* d[][20], char c[][20], int currX,int currY,int direction)
{
	if (d[currX][currY]->getChar() == 'O')
	{
		Organism* temp;
		temp = d[currX][currY];
		delete temp;
		d[currX][currY] = nullptr;
		c[currX][currY] = ' ';

	}

}

char DoodleBug::getChar()
{
	return x;
}

int DoodleBug::checkAnt(Organism* a[][20], char c[][20], int currX,int currY,int direction)
{
	if (currX < 18 && currX>1 && currY < 18 && currY>1)
	{
		if (a[currX][currY - 1] != nullptr && a[currX][currY - 1]->getChar() == 'O')//west
		{
			die(a, c, currX, currY - 1, direction);
			this->food += 1;//food gets incremented as they eat
			return 0;
		}

		if (a[currX - 1][currY] != nullptr && a[currX - 1][currY]->getChar() == 'O' )//north
		{
			die(a, c, currX - 1, currY, direction);
			this->food += 1;//food gets incremented as they eat
			return 1;
		}
		if (a[currX][currY + 1] != nullptr && a[currX][currY + 1]->getChar() == 'O' )//east
		{
			die(a, c, currX, currY + 1, direction);
			this->food += 1;//food gets incremented as they eat
			return 2;
		}
		if (a[currX + 1][currY] != nullptr && a[currX + 1][currY]->getChar() == 'O')//south
		{
			die(a, c, currX + 1, currY, direction);
			this->food += 1;//food gets incremented as they eat
			return 3;
		}
		else
			return direction;
	}
	else
		return direction;
}
bool DoodleBug::hasMoved()
{
	return true;
}
char DoodleBug::getX()
{
	return x;
}