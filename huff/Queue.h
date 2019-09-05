// Class Invariant:  FIFO order
/*
 * Queue.h
 *
 * Class Definition: Queue.h to define the private varibles and public mehtod for Queue
 *
 * 
 * Spring 2019 / CMPT-225 D200
 * Created on: Februar 26 2019
 * Author: Perry Wu  301273743 - plwu@sfu.ca
	   Andy Wang 301329429 - zwa117@sfu.ca
 *
 * None of the provided code (basecode) may be modified.
 */


#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"

#include <cstdio>

using namespace std;

template <class T>
class Queue {
    private:
        //seting a head and a tail to track the linked list
        Node<T> * head;
	Node<T> * tail;
	int len;
        /* Set privete varivables  */

    public:

        // Desc: Constructor. (O(1))
        Queue();

        // // Desc: Destructor. (O(N))
        // ~Queue();

        // Desc: Returns true if Queue is empty. (O(1))
        bool isEmpty() const;


        // Desc: Inserts x at the "back" of this Queue. (O(1))
        void enqueue(const T& x);

        // Desc: Removes the element at the "front". (O(1))
        // Pre: Queue not empty.
        //      Throws EmptyDataCollectionException if Queue empty.
        void dequeue() throw(EmptyDataCollectionException);

        // Desc: Returns the element at the "front". (O(1))
        // Pre: Queue not empty.
        //      Throws EmptyDataCollectionException if Queue empty.
        // Post: Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);

        /* you may add more methods */
};


// Desc: Constructor. (O(1))
template <class T>
Queue<T>::Queue() {
	head = NULL;
	tail = NULL;
	len = 0;
} // constructor



// Desc: Returns true if Queue is empty. (O(1))
template <class T>
bool Queue<T>::isEmpty() const {
	return len == 0;
} // isEmpty



// Desc: Inserts x at the "back
template <class T>
void Queue<T>::enqueue(const T& x) {
  	//create a new node and update the head, tail and len
	Node<T> * newnode;
	newnode = new Node<T>(x);
  	
	//if the Queue is empty
  	if(len == 0){
    		//create a new node and update the head and tail and len
    		head = newnode;
    		tail = newnode;
    		len++;
  	}
  	else{
    		tail->next = newnode;
    		tail = newnode;
    		len++;
  	}
} // enqueue



// Desc: Removes the element at the "front". (O(1))
// Pre: Queue not empty.
//      Throws EmptyDataCollectionException if Queue empty.
template <class T>
void Queue<T>::dequeue() throw(EmptyDataCollectionException) {

	if (head==NULL){
    	// Throws EmptyDataCollectionException if Priority Queue empty.
    		throw EmptyDataCollectionException("PQueue is Empty");
  	}

    	Node<T> * newnode = head;
    	//move head to the next node
    	head = head->next;
    	//release the memory
    	delete newnode;

    	if (head == NULL) {
		// empty list
		tail = NULL;
	}
      	len--; // decrease the length
} // dequeue



// Desc: Returns the element at the "front". (O(1))
// Pre: Queue not empty.
//      Throws EmptyDataCollectionException if Queue empty.
// Post: Queue is unchanged.
template <class T>
T& Queue<T>::peek() const throw(EmptyDataCollectionException) {
	if (head==NULL){
    		// Throws EmptyDataCollectionException if Priority Queue empty.
    		throw EmptyDataCollectionException("PQueue is Empty");
  	}
	return head->data;
} // peek

