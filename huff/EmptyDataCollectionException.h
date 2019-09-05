/*
 * EmptyDataCollectionException.h
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 
#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class EmptyDataCollectionException : public logic_error {
    public:
        EmptyDataCollectionException(const string& message = "");
   
}; // EmptyDataCollectionException 

