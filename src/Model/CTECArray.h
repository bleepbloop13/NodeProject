/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: rbak9218
 */

#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_
#include "ArrayNode.h"


template <class Type>
class CTECArray {
private:
	int size;
	ArrayNode<Type> * Head;
public:
	CTECArray(int size);
	virtual ~CTECArray();
	int getSize();
	void set(int position, Type value);
	Type* get(int position);
};

#endif /* MODEL_CTECARRAY_H_ */
