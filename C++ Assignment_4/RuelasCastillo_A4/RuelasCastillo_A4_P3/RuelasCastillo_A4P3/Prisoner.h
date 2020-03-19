#pragma once
class Prisoner
{
private:
	int prisoner;
	Prisoner* next;
	Prisoner* prev;
public:
	Prisoner();
	Prisoner(int num);
	void addPrisoner(int a);
	Prisoner* remove(int s,Prisoner* pass);
	void setNext(Prisoner*num);
	void setPrev(Prisoner* num);
	int getNum();
	Prisoner* getNext();
	Prisoner* getPrev();
};

