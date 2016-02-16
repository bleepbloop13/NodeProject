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
	notHipsterWorld = new CTECArray<int>(5);

}

NodeController::~NodeController()
{
	// TODO Auto-generated destructor stub
}

void NodeController::start()
{
	arrayTimer.startTimer();

	for(int index = 0; index < notHipsterWorld->getSize(); index++)
	{
		notHipsterWorld->set(index, (index * 13));
	}

	for(int index = notHipsterWorld->getSize()-1; index >= 0; index--)
	{
		cout << "The contents of the notHipsterWorld array node " << index << " are: " << notHipsterWorld->get(index) << endl;
	}

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
}
