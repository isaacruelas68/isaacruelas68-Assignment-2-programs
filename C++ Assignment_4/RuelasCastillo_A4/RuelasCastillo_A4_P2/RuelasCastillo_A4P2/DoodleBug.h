#pragma once
#include "Organism.h"
class DoodleBug : public Organism
{
private:
	char x = 'X';
	int food = 0;
public:
	DoodleBug() :Organism() {};
	void move(Organism* g[][20], char c[][20], int direction, int currX, int currY);
	void breed(Organism* b[][20], char c[][20], int currX, int currY);
	void die(Organism* d[][20],char c[][20], int currX, int currY,int direction);
	char getX();
	void starve(Organism* s[][20], char c[][20], int currX, int currY, int food);
	bool hasMoved();
	int checkAnt(Organism* a[][20], char c[][20], int currX,int currY,int direction);
	char getChar();
	int getFood();
};


