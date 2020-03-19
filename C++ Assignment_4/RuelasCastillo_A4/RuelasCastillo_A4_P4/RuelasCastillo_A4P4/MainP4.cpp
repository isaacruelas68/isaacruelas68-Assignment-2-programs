//ISAAC RUELAS CASTILLO ASSIGMNENT 4 PROBLEM 4
#include <iostream>
#include<string>
#include "CheckedArray.cpp"
using namespace std;
int main()
{
	CheckedArray<int> ary;
	CheckedArray<string> son(15);
	cout << ary[11];//this the test for the exception
	cout << endl;
	cout << ary.length();
	cout << endl;
	cout << son.length();

	
	
	return 1;
}