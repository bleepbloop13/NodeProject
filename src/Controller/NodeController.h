/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: rbak9218
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_
#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/ArrayNode.h"
#include "../Model/CTECArray.cpp"
#include <string>
using namespace std;

class NodeController
{
private:
	CTECArray<int> * notHipsterWorld;
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
