//ISAAC RUELAS CASTILLO ASSIGNMENT 2 PROBLEM 2
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

// Function prototypes
void printMaze(char maze[][WIDTH], int curx, int cury);
bool validMove(char maze[][WIDTH], bool visited[][WIDTH],int newX, int newY);
bool search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y);
void setRandomExit(char maze[][WIDTH]);
int setRandomStart();
void RandX(char maze[][WIDTH]);

// Return true or false if moving to the specified coordinate is valid
// Return false if we have been to this cell already
bool validMove(char maze[][WIDTH], bool visited[][WIDTH],int newX, int newY)
{
	// Check for going off the maze edges
	if (newX < 0 || newX >= WIDTH)
		return false;
	if (newY < 0 || newY >= HEIGHT)
		return false;
	// Check if target is a wall
	if (maze[newY][newX] == 'X')
		return false;
	// Check if visited
	if (visited[newY][newX])
		return false;
	return true;
}


// Display the maze in ASCII
void printMaze(char maze[][WIDTH], int curx, int cury)
{
	
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((x == curx) && (y == cury))
				cout << "@";
			else
				cout << maze[y][x];
		}
		cout << endl;
	}
}

// Recursively search from x,y until we find the exit
bool search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y)
{
	
	if (maze[y][x] == 'E')//this is the base case for the recurision
		return true;

	bool foundExit = false;
	visited[y][x] = true;
	if (validMove(maze, visited, x, y - 1))
	{
		printMaze(maze, x, y);
		cout << endl;
		foundExit = search(maze, visited, x, y - 1);//y moves left
	}
	if (!foundExit && (validMove(maze, visited, x, y + 1)))
	{
		printMaze(maze, x, y);
		cout << endl;
		foundExit = search(maze, visited, x, y + 1);//y moves right
	}
	if (!foundExit && (validMove(maze, visited, x - 1, y)))
	{
		printMaze(maze, x, y);
		cout << endl;
		foundExit = search(maze, visited, x - 1, y);//x moves up
	}
	if (!foundExit && (validMove(maze, visited, x + 1, y)))
	{
		printMaze(maze, x, y);
		cout << endl;
		foundExit = search(maze, visited, x + 1, y);//x moves down
	}
	if (foundExit)
	{
		/*printMaze(maze, x, y);
		cout << endl;*/
		return true;
	}
	return false;
}


int main()
{
	
	char maze[HEIGHT][WIDTH] = {
		   {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
	};
	srand(time(NULL));
	setRandomExit(maze);
	RandX(maze);
	bool visited[HEIGHT][WIDTH];

	int x=0, y=0;
	x = setRandomStart();
	y = setRandomStart();
	bool foundExit = false;

	// Initialize visited locations to false
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGHT; y++)
			visited[y][x] = false;
	visited[y][x] = true;

	search(maze, visited, x, y);
	
}

void setRandomExit(char maze[][WIDTH])
{
	
	int random = rand()%20;
	int random2 = rand() %20;
	if (maze[random][random2] == ' ')
	{
		maze[random][random2] = 'E';
	}
}

int setRandomStart()
{
	return rand()*rand() % 18;
}
void RandX(char maze[][WIDTH])
{

	int random = rand() % 20;
	int random2 = rand() % 20;
	for (int i = 0; i < 100; i++)//100 is 25% of the maze 400*.25=100
	{
		random = rand() % 20;
	    random2 = rand() % 20;
		if (maze[random][random2] == ' ')
		{
			maze[random][random2] = 'X';
		}
	}
}