/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: rbak9218
 */

#include "CTECArray.h"
#include <iostream>
using namespace std;

/**
 * Constructor for the class. Assigns pointers and creates array.
 */
template<class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
	this->head = nullptr;

	//Defensive
	if (size <= 0)
	{
		cerr << "That is not a valid number ya idjit" << endl;
		return;
	}

	for (int index = 0; index < size; index++)
	{

		if (head != nullptr)
		{
			//Regular nodes are being made
			ArrayNode<Type> nextNode;
			nextNode.setNext(head);
			this->head = &nextNode;
		}
		else
		{
			//the first ArrayNode is made;
			ArrayNode<Type> firstNode;
			this->head = &firstNode;
		}
	}
}
/**
 * Returns the size pointer for the array.
 */
template<class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}

/**
 * Sets the value to a specific position. If/else tests if input is out of bounds.
 */
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
		for (int spot = 0; spot <= position; spot++)
		{
			if (spot != position)
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

/**
 * Gets the value at a specific position. If/else tests if position is out of bounds.
 */
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

/**
 * Deconstructs all pointers.
 */
template<class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for (int index = 0; index < size; index++)
	{
		if (deleteMe->getNext() != nullptr)
		{
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);
		}
		delete deleteMe;
		deleteMe = head;
	}
	delete head;
}

