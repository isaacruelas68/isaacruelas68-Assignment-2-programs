//ISAAC RUELAS CASTILLO ASSIGNMENT 2 PROBLEM 3

#include <iostream>
#include<ctime>

using namespace std;


//prototypes
void blankSpace(char m[][40], int topX,int topY, int height, int width);
void printMaze(char m[][40]);
int RandomX( int start, int end);

int main()
{
	srand(time(NULL));

	char maze[40][40];
	
	for (int x = 1; x < 40; x++)
	{
		for (int y = 0; y < 40; y++)//maze creator
		{
			maze[0][y] = 'X';//0->39 X
			maze[x][y] = ' ';//1->39 ' '
			maze[39][y] = 'X';
			maze[y][0] = 'X';
			maze[y][39] = 'X';
			
		}
	}

	



	blankSpace(maze, 1, 1, 39, 39);
	
	printMaze(maze);
	
	
	




}

void blankSpace(char m[][40], int topX, int topY, int height, int width)
{
	int startTwo;
	int one = 0;
	int two;
	int num;
	
	if (width<=2||height<=2)//base case
		return;
	
	if (height >= width)//horizontal lines
	{
		int hold = topX;
		num =RandomX(topY+1,height-2);//height
	
		for (one; one < width; one++)//adds the row of Xs
		{
			m[hold][num] = 'X';
			hold++;
		}
		if (m[topX-1][num] == ' ')//checks left end if blank
			m[topX][num] = ' ';

 		if (m[hold][num] == ' ')//checks right end if blank
			m[hold-1][num] = ' ';
		
		
		m[RandomX(topY,width-1)][num] = ' ';//this makes a rand slot in the new wall a blank//topY=2, w=39 ->w=38
		
		int top = num - 1;//top half of matrix
		int bottom = height - num;//bottom half of the matrix
		if (width > 2)
		{	
			 two=width-2;
			startTwo =width- two;
		}
		//below are the two recursive call options
		
		 
		//this resets the bool since the previous set it to false.
		printMaze(m);
		blankSpace(m, startTwo, num+1, bottom-1, width); //BOTTOM recursive call to the Vertical

		printMaze(m);
		if (height > 2)//if this function is leads to true run other wise go to else
			blankSpace(m, startTwo, topY, top, width); //TOP recursive call to the Vertical if statement
	}
	    



	if (width > height)//vertical lines
	{
		
		int hold = topY;
		int space;
		int ogWidth = 39;
		int widthHolder;
		
		num = RandomX(topX+1,width+(topX-1));//(switchloop pick,left side start of vertical,right side of vertical space)
		
		for (one; one < height; one++)//adds the row of Xs (WALLS)//possible error height ran 25 times
		{
			m[num][hold-1] = 'X';
			hold++;
		}
		if (hold > 40)
		{
			hold -= 2;
		}
		if (m[num][height+1] == ' ')//checks top end if blank
			m[num][height] = ' ';

		if (m[num][hold] == ' ')//checks bottom end if blank
			m[num][hold-1] = ' ';

		m[num][RandomX(topY+1,hold-1)] = ' ';//this makes a rand slot in the new wall a blank//hold might need to be 1??
		
		//the two recursive call options
		int newTopY = width - 2; 
		widthHolder = ogWidth - num;
		
		printMaze(m);
		if (width > 2)
			blankSpace(m, hold, width - newTopY, height, num);//left side

		printMaze(m);
		blankSpace(m, num + 1, topY, height, width+widthHolder);//right side//posible error try next time width+topX and see if that works
		
		
		
		
			
		
		
	}



	return;

}

//void blankSpace(char m[][40], int topX, int topY, int height, int width)
//{
//	if (height <= 2 || width <= 2)
//		return;
//
//	if (height >= width)//horizontal line
//	{
//		int x=1;
//		int counter = 0;
//		int end = 39;
//		int y = RandomX(topY, height);
//
//		for (counter; counter < width; counter++ )//adds the row of Xs
//		m[counter][y] = 'X';
//
//		if (m[x-1][y] == ' ')//checks left end if blank
//			m[x][y] = ' ';
//
//		if (m[counter][y] == ' ')//checks right end if blank
//			m[x-1][y] = ' ';
//
//		m[RandomX(topX, width - 1)][y] = ' ';
//
//		printMaze(m);
//		blankSpace(m, topX, topY, height - y, width);//bottom
//
//		blankSpace(m, topX, topY,y , width);
//	}
//
//	if (width > height)//VERTICAL
//	{
//		int y = 1;
//		int counter = 0;
//		int end = 39;
//		int x = RandomX(topY, width);
//
//		for (counter; counter < height; counter++)//adds the row of Xs
//			m[x][counter] = 'X';
//
//		if (m[y - 1][x] == ' ')//checks left end if blank
//			m[y][x] = ' ';
//
//		if (m[counter][x] == ' ')//checks right end if blank
//			m[y - 1][x] = ' ';
//
//		m[RandomX(topY, height - 1)][x] = ' ';
//
//		printMaze(m);
//		blankSpace(m, topX, topY, width - x, height);//bottom
//
//		blankSpace(m, topX, topY, y, width);
//
//	}
//
//}






void printMaze(char m[][40])
{

	for (int y=0; y < 40; y++)
	{
		for (int x=0; x < 40; x++)
		{
			cout << m[x][y];
		}
		cout << endl;
	}
}

int RandomX(int start , int end )
{
	int num=0;
	int measure;
	int counter = 1;


			if(start>end)
			{
				//cout << "start is bigger than end";
				return end;
			}

			if(end>39)
			{
				measure=end-38;
				end = end - measure;
			}

			while (num<start || num>end)//will run until num is between start and end;
			{
				num = rand() % end;
				if (num ==0)
					return start;

				if (num <= start)
					num += start;
			}
			return num;
			
}
