#include "PrisonerList.h"
PrisonerList::PrisonerList()
{
	head = nullptr;
}
PrisonerList::PrisonerList(Prisoner* c)
{
	head = c;
}
PrisonerList::~PrisonerList()
{
	Prisoner* temp;
	while (head != nullptr) {
		temp = head;
		head = head->getNext();
		delete temp;
	}

}
void PrisonerList::add(int s)
{
		// Make a new node that points to head
		Prisoner* temp = new Prisoner(s);
		temp->setPrev(head);
		head->setNext(temp);
		

}
void PrisonerList::remove(int s)
{
	Prisoner* temp = head;
	Prisoner* prev = nullptr;
	while (temp != nullptr)
	{
		if (temp->getNum() == s)
		{
			if (prev == nullptr)
				head = head->getNext(); // Delete head of the list
			else
				prev->setNext(temp->getNext()); // Deleting past the head
			delete temp;
			break;
		}
		prev = temp;
		temp = temp->getNext();
	}

}
void PrisonerList::output()
{

}