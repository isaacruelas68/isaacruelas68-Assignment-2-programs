#pragma once
#include "Organism.h"
class null: Organism
{
	/*private:
		char* nothing = nullptr;*/
public:
	null() :Organism() {};
	void move();
	void breed();
	void die();
	char* nothing = nullptr;
};

