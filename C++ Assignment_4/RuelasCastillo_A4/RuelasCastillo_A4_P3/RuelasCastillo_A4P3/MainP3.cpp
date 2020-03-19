//ISAAC RUELAS CASTILLO ASSIGNMENT 4 PROBLEM 3

#include<iostream>
#include<stdio.h>
#include<string>
#include"Prisoner.h"
#include"PrisonerList.h"
using namespace std;
void print(string a, int length);
int main()
{
	cout << "welcome to the Death game young ruler" << endl;
	cout << "how many prisoners would you like to see get executed? " << endl;
	int pris;
	cin >> pris;

	cout << "ahhh nice, okay what length would you like to sing? " << endl;
	int songLength;
	cin >> songLength;

	cout << "very well you chose to execute " << pris << " prisoners and the song will be of length "<<songLength<<endl;
	
	
	Prisoner* start=new Prisoner(1);
	PrisonerList* headptr= new PrisonerList(start);
	Prisoner* follow;
	Prisoner* tail;
	
	 follow = start;
	 tail = follow;

	
	int currPris = 2;
	for (int run = 1; run < pris; run++)//this for loop creates the prisoner linked list
	{
		
		follow->setNext(new Prisoner(currPris));
		follow->getNext()->setPrev(follow);
		
		
			follow = follow->getNext();

			if (run == pris-1)//the last run sets the tail to the end and sets the tail next to the head
			{
				tail = follow;
				tail->setNext(start);
				start->setPrev(tail);
			}
			currPris++;
		
	}
	follow = start;
	while (follow->getNext()!=follow)//if this dont work use headptr instead
	{
		
		for (int i = 1; i <songLength; i++)
		{
			follow=follow->getNext();//follow will traverse through the linked list
			if (i == songLength - 1)
			{

				follow=follow->remove(follow->getNum(), follow);
				
			}
		}

	}
	cout << "if I were you I would be prisoner " << follow->getNum() << endl;







}
