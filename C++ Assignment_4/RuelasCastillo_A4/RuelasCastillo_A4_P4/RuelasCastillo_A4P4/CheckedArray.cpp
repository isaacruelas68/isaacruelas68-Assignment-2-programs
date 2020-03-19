#include "CheckedArray.h"
#include<iostream>
template<class T>
CheckedArray<T>::CheckedArray()
{
	size = 10;
	p = new T[size];
}
template<class T>
CheckedArray<T>::CheckedArray(int size)
{
	this->size=size;
	p = new T[size];
}


template<class T>
CheckedArray<T>::~CheckedArray()
{
	delete p;
	std::cout << "deleting all the memory"<<std::endl;
	
}

	template<class T>
	T& CheckedArray<T>::operator[](int index)
	{
		try
		{
			if (index > sizeof(p))
				throw 1;

		}
		catch (int e)
		{
			std::cout << "Array Out of Range"<<" was caused by index: "<<index;
		}
	}
template<class T>
int CheckedArray<T>::length()
{
	return size;
}
