/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list (template)
 *                   Designed and implemented as a non-ADT.
 *
 * Spring 2019 / CMPT-225 D200
 * Created on: Februar 26 2019
 * Author: Perry Wu  301273743 - plwu@sfu.ca
	   Andy Wang 301329429 - zwa117@sfu.ca
 */
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
// and it means: do not include me more than once.

#pragma once

#include <cstdio>   // Needed for NULL
#include <string> // for string class
using namespace std;


template <class T>
class Node {

    public:
      T data;       // The data for any data type in the node
      Node* next;   // Pointer to next node
      // Constructors
      Node(T theData);
      Node(T theData, Node* theNextNode);

}; // Node


//define the constructors
template <class T>
Node<T>::Node(T theData) {
	data = theData;
	next = NULL;
}
//define the constructors
template <class T>
Node<T>::Node(T theData, Node* theNextNode) {
	data = theData;
	next = theNextNode;
}
