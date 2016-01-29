/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: rbak9218
 */

#include "NodeController.h"
#include <iostream>
using namespace std;

NodeController::NodeController()
{
	stringNode.setValue("salad");
	intNode.setValue(6969);

	stringArrayNode.setValue("Words in here :D");
	otherArrayNode.setValue("linked node");
	stringArrayNode.setNext(&otherArrayNode);
}

NodeController::~NodeController()
{
	// TODO Auto-generated destructor stub
}

void NodeController::start()
{
	cout <<"The contents of stringNode are " <<stringNode.getValue() << endl;
	cout <<"The contents of stringArrayNode are " << stringArrayNode.getValue() << endl;
	cout <<"This is connected to stringArrayNode " << (*stringArrayNode.getNext()).getValue() << endl;
}
