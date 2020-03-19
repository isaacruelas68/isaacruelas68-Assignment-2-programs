#pragma once
template<class T>
class CheckedArray
{
private: 
	T* p;
	int size;
public:
	CheckedArray();
	CheckedArray(int size);
	~CheckedArray();
	T& operator[](int index);// throw (ArrayOutOfRange);
	int length();

};

