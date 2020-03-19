#include "Prisoner.h"
#include"PrisonerList.h"
#include<iostream>
Prisoner::Prisoner()
{
	prisoner = 0;
	next = nullptr;
	prev = nullptr;
}
Prisoner::Prisoner(int num)
{
	prisoner = num;
	next = nullptr;
	prev = nullptr;
}

void Prisoner::setNext(Prisoner* num) 
{
	next =num;
}
void Prisoner::setPrev(Prisoner* num)
{
	prev = num;
}
int Prisoner::getNum()
{
	return prisoner;
}
Prisoner* Prisoner::getNext()
{
	return next;
}
Prisoner* Prisoner::getPrev()
{
	return prev;
}

void Prisoner:: addPrisoner(int a)
{
		// Make a new node that points to head
		Prisoner* temp = new Prisoner(a);
		temp->setPrev(this);
		next = temp;
		
	
}
Prisoner* Prisoner::remove(int s,Prisoner* pass)
{

	Prisoner *temp=pass;
	Prisoner* prev = nullptr;
	Prisoner* connect = pass;
	while (temp->getNext() != nullptr)
	{
		if (temp->getNum() == s)
		{
			if (prev == nullptr)
			{
				connect = connect->getPrev();//sets list before the block we want to delete
				connect->setNext(pass->getNext());//sets the next before to the next one jumping over the one we want to delete
				connect->getNext()->setPrev(pass->getPrev());//sets the previos to jump back over the one we want to delete. 


				pass = connect;
				pass=pass->getNext();
			}
			delete temp;
			return pass;
		}
		prev = temp;
		temp=temp->getNext();
	}


}
