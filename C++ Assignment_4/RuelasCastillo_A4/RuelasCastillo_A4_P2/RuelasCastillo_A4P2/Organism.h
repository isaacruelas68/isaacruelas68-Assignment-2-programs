#pragma once
class Organism
{
private:
	char null = '0';
	friend class DoodleBug;
	int food = 0;
public:
	Organism();
	/*char* getnull();*/
	virtual void move(Organism* g[][20],char c[][20], int direction, int currX, int currY);
	virtual void breed(Organism* b[][20], char c[][20], int currX, int currY);
	virtual void die(Organism* d[][20], int currX, int currY, int direction);
	virtual bool hasMoved();
	virtual char getChar();
	virtual void starve(Organism* s[][20], char c[][20], int currX, int currY, int food);
	virtual int getFood();
};

