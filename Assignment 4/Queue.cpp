/*
 * Queue.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: student
 */

#include <iostream>
using namespace std;
#include "Queue.h"

Queue::Queue() {
	mySize = 0;
	first = NULL;
	last = NULL;
}

void Queue::enqueue(ElementType &a, float &b) {

	NodePointer nPtr = new Node();
	nPtr->id = a;
	nPtr->enqueue_Time = b;
	NodePointer predPtr = first;

	if (first == NULL) {               // Insert if queue is empty
		nPtr->next = first;
		first = nPtr;
	} else {						   // Insert into the queue at the end
		while(predPtr->next) {
			predPtr = predPtr->next;
		}
		predPtr->next = nPtr;
	}
	mySize++;
	last = nPtr;
}

void Queue::dequeue() {

	if(first) {
		NodePointer dPtr = first;
		first = first->next;		   // Set first to the second node in the list
		delete dPtr;				   // Delete the node that has been dequeued
	}
	mySize--;
}

int Queue::getSize() {
	return mySize;
}

Queue::~Queue() {
	if (first) {
		NodePointer current = first;
		NodePointer temp = first;

		temp = current->next;
		delete current;
		current = temp;
	}
}


