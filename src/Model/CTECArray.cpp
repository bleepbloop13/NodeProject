/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: rbak9218
 */

#include "CTECArray.h"
#include <iostream>
using namespace std;

template<class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
}

template<class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}

template<class Type>
void CTECArray<Type>::set(int position, Type value)
{
	if (position >= size || position < 0)
	{
		cerr << "position value is out of bounds :(" << endl;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= position; spot++)
		{
			if(spot != position)
			{
				current = current->getNext();
			}
			else
			{
				current->setValue();
			}
		}
	}
}

template<class Type>
Type* CTECArray<Type>::get(int position)
{
	if (position >= size || position < 0)
	{
		cerr << "position value is out of bounds :(" << endl;
		return nullptr;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= position; spot++)
		{
			if (spot != position)
			{
				current = current->getNext();
			}
			else
			{
				return current->getValue();
			}
		}
	}
}

template<class Type>
CTECArray<Type>::~CTECArray()
{
	// TODO Auto-generated destructor stub
}

