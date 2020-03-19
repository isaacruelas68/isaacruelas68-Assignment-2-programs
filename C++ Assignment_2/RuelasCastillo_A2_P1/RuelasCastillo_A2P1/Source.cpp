//ISAAC RUELAS CASTILLO ASSIGNMENT 2 PROBLEM 1
#include <iostream>
using namespace std;
int main()
{
	int nums[20] = { 0 };
	int a[10] = { 0 };
	cout << a << endl;//this just prints the address of array a
	cout << nums << endl;//prints adress of nums
	cout << "How many numbers? (max of 10)" << endl;
	cin >> nums[0];
	for (int i = 0; i < nums[0]; i++)
	{
		cout << "Enter number " << i << endl;
		cin >> a[i];
	}
	// Output the numbers entered
	for (int i = 0; i < 10; i++)
		cout << a[i] << endl;
	return 0;
}
/*
the program did not loop 255 times becuase it exceeded the capacity of array a[10].The for loop in line 11 runs to 255 but the input is of size 10, 
then code goes to twelf becuase of the way c is written it lets you go past the array limit with the cost of overrwriting anything that is placed 
bleow in the stack. Also the program doesnt check if the person actually entered the number that it displays in line 13, it only saves it. 

The program then crashes because the stack around the variable 'nums' gets corrupted becuae the forloop never finishes since its supposed to run until 255.


*/