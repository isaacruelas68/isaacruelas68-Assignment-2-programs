#pragma once
#include "Organism.h"
class Ant :public Organism
{
private:
	char o = 'O';

public:
	Ant() :Organism() {};
	void move(Organism* g[][20], char c[][20], int direction, int currX, int currY);
	void breed(Organism* b[][20], char c[][20], int currX, int currY);
	void die(Organism* d[][20], int currX, int currY, int direction);
	char getO();
	bool hasMoved();
	char getChar();
};

