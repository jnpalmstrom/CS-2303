/*
 * Queue.h
 *
 *  Created on: Feb 12, 2017
 *      Author: student
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Teller_s {
	bool active;
	int time_At;
	int id;
	int count;
};

typedef int ElementType;

class Queue {
public:

	class Node {
	public:
		ElementType id;
		ElementType enqueue_Time;
		ElementType dequeue_Time;

		Node *next;
		Node() {
			// Node Constructor
			id = 0;
			enqueue_Time = 0;
			dequeue_Time = 0;
			next = NULL;
		}
	}; 									// end of Node class

	typedef Node *NodePointer;


	Queue();                       		// Default Constructor

	void enqueue(ElementType &a, float &b);                		// Add to the back of the queue

	void dequeue();				   		// Remove from the front of the queue

	//Returns the front of the queue
		NodePointer front() {

			if (first) {
				NodePointer ptr = first;
				return ptr;
			}
			return NULL;
		}
	//Return size of the queue
		int getSize();
	//Return arrive time
		ElementType enqueueTime(NodePointer p){
			return p->enqueue_Time;
		}
		ElementType dequeueTime(NodePointer p){
			return p->dequeue_Time;
		}
		int getId(NodePointer p){
			return p->id;
		}
	//Destructor
		~Queue();
	private:
		Node *first;
		Node *last;
		int mySize;
	};

#endif /* QUEUE_H_ */
