/*
 * LetterRecord.h
 *
 * Class Definition: LetterRecord.h is obejct to store frequency and its character.
 *
 * Spring 2019 / CMPT-225 D200 
 * Created on: Mar 20, 2019
 * Author: Perry Wu  301273743 - plwu@sfu.ca
	   Andy Wang 301329429 - zwa117@sfu.ca
 */
#include <iostream>
#include <fstream>
#include "LetterRecord.h"
#include <cstdio>  // Needed for NULL
using namespace std;

// constructor;
// initialize all factors
LetterRecord::LetterRecord(){
	frequency = 0;        // frequency for a character
	index = -1;           // (index-128) is corresdoning to the character in ASCII table
	is_leaf = false;
	left = NULL;
	right = NULL;
	parent = NULL;
	weight = 0;
};

// Desc: Returns the frequency
int LetterRecord::Get_frequency() const{
	return frequency;
};

// Desc: Returns the index
int LetterRecord::Get_index() const{
	return index;
};

// Desc: Returns if this leaf
bool LetterRecord::Get_is_leaf() const{
	return is_leaf;
};

// create frequency setters
void LetterRecord::Set_frequency(unsigned freq){
	frequency = freq;
};

// create index setters
void LetterRecord::Set_index(unsigned length){
	index = length;
};

// create boolean setters
void LetterRecord::Set_is_leaf(bool if_true){
	is_leaf = if_true;
};
