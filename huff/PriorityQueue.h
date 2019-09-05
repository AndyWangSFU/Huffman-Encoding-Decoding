/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 * Class Invariant:  FIFO order
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
class PriorityQueue {

    private:
        // singly-linked list
        Node<T>* head;
        int len;

        /* You may add private methods to this class */

    public:
        // Desc: Default Constructor. (O(1))
        PriorityQueue();

        // Desc: Copy Constructor. (O(N))
        PriorityQueue(const PriorityQueue& rhs);

        // Desc: Destructor. (O(N))
        ~PriorityQueue();

        // Desc: Returns true if Priority Queue empty. (O(1))
        bool isEmpty() const;

        // Desc: Returns length of the Priority Queue. (O(1))
        int getLength() const;

        // Desc: Inserts x in sorted order. (O(N))
        //  Pre: Priority Queue is sorted.
        // Post: Priority Queue remains sorted.
        void enqueue(const T& x);

        // Desc: Removes the element with "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        T* dequeue();



}; // PriorityQueue

//default constructor
template <class T>
PriorityQueue<T>::PriorityQueue(){
	head = NULL;
	len = 0;
}


// Desc: Copy Constructor. (O(N))
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhs){

        //first condition: if rhs is empty
	if(rhs.isEmpty()){
    		head = NULL;
    		len = 0;
	}

  	else{
    		Node<T>* curr;			            // create a node point to rhs
    		Node<T>* newcop;			    // create a node point to new queue
    		curr = rhs.head;			    // point to rhs
    		newcop = new Node<T>(curr->data);  	    // create a node point to new queue
    		head = newcop;				    // define the head
    		len = rhs.getLength();			    // get length of rhs
    		newcop = newcop->next;			    // move to the next step
    		curr = curr->next;

    		//deep copy the data from rhs to a new Queue
    		while(curr != NULL){
      			newcop = new Node<T>(curr->data);   // create a new node
      			newcop = newcop->next;
      			curr = curr->next;
		}
       }
}


// Desc: Destructor. (O(N))
template <class T>
PriorityQueue<T>::~PriorityQueue(){
  	Node<T>* curr;
    	while(head != NULL){
    		curr = head;
    		head = head->next;
    		delete curr;
	}
  	len=0;
}


// Desc: Returns true if Priority Queue empty. (O(1))
template <class T>
bool PriorityQueue<T>::isEmpty() const{
	return len == 0;
}


// Desc: Returns length of the Priority Queue. (O(1))
template <class T>
int PriorityQueue<T>::getLength() const{
  	return len;
}



// Desc: Inserts x in sorted order. (O(N))
// Pre: Priority Queue is sorted.
// Post: Priority Queue remains sorted.
template <class T>
void PriorityQueue<T>::enqueue(const T& x){

  	//reach the end of the Queue or  compare the head's priority with x
	if (head == NULL || x> head->data){
		Node<T>* tempNode = new Node<T>(x, head);       //insert the x brefore head
		head = tempNode;                                // update head
		len++;                                          //increase the length
		return;
	}

	Node<T>* current = head;                         	//create two pointers for head
	Node<T>* previous =head;

  	//search the next that is NULL or  higher priority than x
	while(current != NULL && (x <= current->data) ){
		previous = current;
		current = current->next;
	}

  	//insert thr newnode between the previous and current
	Node<T>* tempNode = new Node<T>(x, previous->next);
	previous->next = tempNode;
	len++;
	return;
}





// Desc: Removes thT* e element witeadh "highest" priority. (O(1))
// Pre: Priority Queue not empty.
//      Throws EmptyDataCollectionException if Priority Queue empty.
template <class T>
T* PriorityQueue<T>::dequeue(){

	if (head==NULL){
    		// Throws EmptyDataCollectionException if Priority Queue empty.
      return NULL;
 	}

    	len--;               //decrease the Length
      Node<T>* tempNode = head;
      head = head->next;

      return &(tempNode->data);
}
