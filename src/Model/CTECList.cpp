/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: rbak9218
 */

#include <iostream>
#include <assert.h>
#include "CTECList.h"

template<class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

template<class Type>
CTECList<Type>::~CTECList()
{

}

template<class Type>
int CTECList<Type>::getSize()
{
	return size;
}

template<class Type>
Type CTECList<Type>::set(int index, const Type& value)
{
	assert(index < size && index >= 0);

	ArrayNode<Type> * current = head;
	Type returnValue;
	for (int spot = 0; spot <= index; spot++)
	{
		if (spot != index)
		{
			current = current->getNext();
		}
		else
		{
			returnValue = current->getValue();
			current->setValue(value);
		}
	}
	return returnValue;
}

template<class Type>
void CTECList<Type>::addToFront(const Type& value)
{
	ArrayNode<Type> * current = head;
	ArrayNode<Type> * newFirst = new ArrayNode<Type>(value);

	newFirst->setNext(current);
	head = newFirst;
	calculateSize();
}

template<class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	assert(size > 0);
	assert(index > 0);
	assert(index < size);

	ArrayNode<Type> * currentSpot = head;
	ArrayNode<Type> * nextSpot;
	ArrayNode<Type> * newNext;
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);

	for (int spot = 0; spot < index + 1; index++)
	{

		if (spot == index - 1)
		{
			newNext = newNode;
			currentSpot->setNext(newNext);
			newNext->setNext(nextSpot);

		}

		if (spot == index + 1)
		{
			nextSpot = currentSpot->getNext();
		}

		currentSpot = currentSpot->getNext();
	}
	calculateSize();
}

template<class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
	assert(size > 0);

	ArrayNode<Type> * newEnd = new ArrayNode<Type>(value);
	ArrayNode<Type> * currentSpot = end;
	ArrayNode<Type> * newNext = newEnd;

	currentSpot->setNext(newNext);
	newNext->setNext(nullptr);
	calculateSize();
}

template<class Type>
Type CTECList<Type>::removeFromFront()
{
	Type thingToRemove;
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = this->head->getNext();
	thingToRemove = this->head->getValue();
	calculateSize();
	return thingToRemove;
}

/*
 * Loops to last node to remove that node , and sets the preceding node to end.
 * If size == 1, removes the only value.
 */
template<class Type>
Type CTECList<Type>::removeFromEnd()
{
	assert(size > 0);

	Type returnValue;
	if (size == 1)
	{
		ArrayNode<Type> * toRemove = end;
		returnValue = removeFromFront();
		end = nullptr;
		head = nullptr;
		delete toRemove;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for (int pos = 0; pos < size - 1; pos++)
		{
			current = current->getNext();
		}
		returnValue = end->getValue();
		delete end;
		current = end;
	}
	calculateSize();
	return returnValue;
}

template<class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
	assert(size > 0 && index >= 0 && index < size);

	Type thingToRemove;
	ArrayNode<Type> * current = head;
	ArrayNode<Type> * previousSpot;
	ArrayNode<Type> * newNext;

	for (int spot = 0; spot < index + 1; spot++)
	{
		if (spot == index - 1)
		{
			previousSpot = current;
		}
		if (spot == index)
		{
			thingToRemove = current->getValue();
			newNext = current->getNext();
			delete current;
		}
		current = current->getNext();
	}
	previousSpot->setNext(newNext);
	calculateSize();
	return thingToRemove;
}

template<class Type>
void CTECList<Type>::calculateSize()
{
	assert(size >= 0);

	int count = 0;

	if (head == nullptr)
	{
		size = 0;
	}
	else
	{
		count++;
		ArrayNode<Type> * current = head;
		while(current->getNext() != nullptr)
		{
			count++;
			current = current->getNext();
		}
	}
}
