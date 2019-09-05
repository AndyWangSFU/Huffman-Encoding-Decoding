/*
 * EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 

#include "EmptyDataCollectionException.h"  

EmptyDataCollectionException::EmptyDataCollectionException(const string& message): logic_error("Empty Data Collection ADT Class Exception: " + message) {
}  // constructor

