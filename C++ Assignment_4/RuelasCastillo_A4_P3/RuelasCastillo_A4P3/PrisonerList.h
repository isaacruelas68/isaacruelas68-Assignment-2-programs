#pragma once
#include"Prisoner.h"
class PrisonerList
{
private:
	Prisoner* head; // Points to the first thing in the list
public:
	PrisonerList();
	PrisonerList(Prisoner* c);
	~PrisonerList();
	void add(int s); // Adds to front of list
	void remove(int s); // Deletes first occurrence of s in the list
	void output(); // Output everything in the list
	
};


