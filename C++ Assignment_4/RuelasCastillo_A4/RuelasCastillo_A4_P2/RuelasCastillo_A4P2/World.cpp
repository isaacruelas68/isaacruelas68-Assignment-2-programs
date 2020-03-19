//ISAAC RUELAS CASTILLO ASSIGNMENT 4 PROBLEM 2

#include<iostream>
#include<ctime>
#include "Organism.h"
#include "Ant.h"
#include "DoodleBug.h"
#include "null.h"
#include <cstdlib>
#include <typeinfo>
using namespace std;
const int SIZE = 20;

//prototypes
 int random();
 int dirRand();
 void visualCell(char c[][SIZE]);
 void gridCell(Organism* g[][SIZE]);
 void printCell(char cell[][SIZE]);
 void printGrid(Organism* grid[][SIZE]);
 bool checkExist(Organism* grid[][SIZE]);
 

int main()
{
	 int DAY = 1,rands;
	char quit = 'q';
	Organism* grid[SIZE][SIZE];//pointer cell
	char cell[SIZE][SIZE];//visual cell


	visualCell(cell);//calls to create the maze
	gridCell(grid);//calls to create the grid cell

	
	

	srand(time(NULL));//sets the time to a randomm 

	for (int doodle = 0; doodle < 5; doodle++)//this loop creates the doodlebugs
	{
		int h1 = 0, h2 = 0;
		//DoodleBug* bug = new DoodleBug();
		grid[h1 = random()][h2 = random()] = new DoodleBug();//bug;
			cell[h1][h2] = 'X';
			
	}
	
	for (int ant = 0; ant < 100; ant ++)//this loop creates the ants
	{
		int h1=0, h2=0;
		Ant* ants = new Ant();
		if (grid[h1 = random()][h2 = random()] == nullptr)
			grid[h1][h2] = ants;

		if (cell[h1][h2] == ' ')//this mocks the grid world
			cell[h1][h2] = 'O';
	}
	
	char nextDay=' ';

	//MAIN SIMULATION LOOP
	while (nextDay!=quit)//isert here whether ant or DB is extint run or q for quit//MAIN LOOP FIXXXX
	{
		int hunger = 0, breeds = 0;
		cout << "Day: " << DAY << endl;
		printCell(cell);

	
		for(int i=0;i<20;i++)//this runs through the etire array
			for (int p = 0; p < 20; p++)
			{
				if(grid[i][p]!=nullptr && grid[i][p]->getChar()=='X')//this should move only the doodle bugs
				grid[i][p]->move(grid, cell, dirRand(), i, p);//(grid,cell,direction,currX,currY)

			}

		breeds = DAY % 8;
		if (breeds==0)//mod 8 the doodlebugs breed
		{
			for (int x = 0; x < 20; x++)//this runs through the etire array
				for (int y = 0; y < 20; y++)
				{
					if (grid[x][y] != nullptr && grid[x][y]->getChar() == 'X')//this should move only the doodle bugs
						grid[x][y]->breed(grid, cell,x,y);//(grid,cell,direction,currX,currY)
				}
		}

		hunger = DAY % 3;
		if (hunger==0)//mod3 the doodlebugs starve
		{
			for (int i = 0; i < 20; i++)//this runs through the etire array
				for (int p = 0; p < 20; p++)
				{
					if (grid[i][p] != nullptr && grid[i][p]->getChar() == 'X')//this should move only the doodle bugs
						grid[i][p]->starve(grid, cell, i,p, grid[i][p]->getFood());//(grid,cell,direction,currX,currY)
				}

		}

		//////////////////THE ANTS TURN
		for (int i = 0; i < 20; i++)//this moves the ants
			for (int p = 0; p < 20; p++)
			{
				if (grid[i][p] != nullptr && grid[i][p]->getChar() == 'O')//this should move only the ants
					grid[i][p]->move(grid, cell, dirRand(), i, p);//(grid,cell,direction,currX,currY)
			}

		breeds = DAY % 3;
		if (breeds == 0)//mod 8 the doodlebugs breed
		{
			for (int i = 0; i < 20; i++)//this runs through the etire array
				for (int p = 0; p < 20; p++)
				{
					if (grid[i][p] != nullptr && grid[i][p]->getChar() == 'O')//this should move only the doodle bugs
						grid[i][p]->breed(grid, cell, i, p);//(grid,cell,direction,currX,currY)
				}
		}

		
		
		DAY++;
		cout << "Please enter any key to continue or 'q' to quit ";
		cin >> nextDay;
	}
	
	 
}





////FUNCTIONS
int dirRand()
{
	int hold;
	return hold = rand() % 4;

}

bool checkExist(Organism* t[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int p = 0; p < SIZE; p++)
		{
			if ((typeid(&t[1][2]) == typeid(Ant*)))
			{
			return true;
			}
			if ((typeid(t[i][p]) == typeid(DoodleBug*)))
			{
				return true;
			}
		 }
	}
	return false;

}




void printCell(char cell[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int p = 0; p < SIZE; p++)
		{
			cout << cell[i][p];
		}
		cout << endl;
	}

}


void printGrid(Organism* grid[][SIZE])//thing for later is getting it to print from grid rather than cell
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int p = 0; p < SIZE; p++)
		{
			cout << grid[1][2];
		}
		cout << endl;
	}

}


void gridCell(Organism* g[][SIZE])
{
	for (int x = 0; x < SIZE; x++)//sets all blocks to nullptr
		for (int y = 0; y < SIZE; y++)
			g[y][x]=nullptr;

}



void visualCell(char c[][SIZE])
{
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			c[y][x] = ' ';

	// Borders with l
	for (int x = 0; x < SIZE; x++)
	{
		c[0][x] = 'l';
		c[SIZE - 1][x] = 'l';
	}
	for (int y = 0; y < SIZE; y++)
	{
		c[y][0] = 'l';
		c[y][SIZE - 1] = 'l';
	}

}
int random()
{
	int rands;
		rands = rand() % 20;
	
			if (0 < rands && rands < 19)
				return rands;
			else
				return random();
	
}
