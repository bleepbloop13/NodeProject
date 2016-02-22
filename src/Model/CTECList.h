/*
 * CTECList.h
 *
 *  Created on: Feb 22, 2016
 *      Author: rbak9218
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_
#include "ArrayNode.h"

template <class Type>
class CTECList
{
private:
	int size;
	ArrayNode<Type> * head;
	ArrayNode<Type> * end;
public:
	CTECList();
	virtual ~CTECList();
	int getSize();
	void addToFront(const Type& value);
	Type getFront();
	Type getEnd();
	Type getFromIndext(int index);
	Type removeFromEnd();
	Type removeFromFront();
	Type removeFromIndex(int index);
	Type set(int index, const Type& value);
};

#endif /* MODEL_CTECLIST_H_ */
