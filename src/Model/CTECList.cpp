/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: rbak9218
 */

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
	// TODO Auto-generated destructor stub
}

template<class Type>
int CTECList<Type>::getSize()
{
	return size;
}
