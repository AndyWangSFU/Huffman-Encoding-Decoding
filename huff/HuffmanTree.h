/*
 * HuffmanTree.h
 *
 * Class Definition: To build the tree based on the frequency of each
 * 		     character from FrequencyCounter.h
 *
 *
 * Spring 2019 / CMPT-225 D200
 * Created on: Mar 19, 2019
 * Author: Perry Wu  301273743 - plwu@sfu.ca
	   Andy Wang 301329429 - zwa117@sfu.ca
 */
#include <iostream>
#include <fstream>
#include "FrequencyCounter.h"
#include "PriorityQueue.h"
#include "LetterRecord.h"
#include <string>  // for string class
#include <cstdio>  // Needed for NULL
using namespace std;
#pragma once


class HuffmanTree{
	    public:
            //Pre:  The frequency_table is not empty.
            //Desc: The function uses to create a node and build a tree
            //Pos:  Return the node of tree
            LetterRecord* BuildHuffTree(FrequencyCounter& frequency_table);

	    //Pre:  HuffTree is builded
            //Desc: Create a digit sequence to represent the character
            //Pos:  Digits are created
	    void StoreDigit(LetterRecord* root, string digit, string DigitHouse[]);
}; 
