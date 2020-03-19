//ISAAC RUELAS CASTILLO ASSIGNMENT 2 PROBLEM 4
#include<iostream>
using namespace std;

//prototypes
void Decoder(char c[], int key);

int main()
{

	char code[] = { ",vtaNm a_\"dabp!!" };
	int key = 1;
	Decoder(code, key);

}
void Decoder(char c[],int key)
{
	char copy[16];
	char temp[4];
	char* letters;
	int* num;
	int size = 4;
	int index = 0;
	int start = 0;
	
	while (key < 501)
	{
		for (int length = 0; length < 16; length++)//this copies the c array to copy
			copy[length] = c[length];

		for (int run = 0; run < 4; run++)//this runs four times and breaks the 16 char word into bit
		{
			for (int zero = 0; zero < size; zero++)//this saves copy to a temp array
			{
				temp[zero] = copy[index];
				index++;
			}
				num = (int*)temp;//this code transfers the temp array to int and then back to a char
				*num = *num - key;
				letters = (char*)num;
				for(int p=0;p<sizeof(temp);p++,start++)
				copy[start] = letters[p];

				
			
		}
		for (int p = 0; p < 16; p++)//this loop prints out the changed array.
		{
			cout << copy[p];
		}

		cout << " key is: " << key << endl;
		key++;
		index = 0;
		start = 0;
	}

	
}