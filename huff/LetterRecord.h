/*
 * LetterRecord.h
 *
 * Class Definition: This obejct is to store the frequency and its corresponding character.
 *
 * Spring 2019 / CMPT-225 D200 
 * Created on: Mar 20, 2019
 * Author: Perry Wu  301273743 - plwu@sfu.ca
	   Andy Wang 301329429 - zwa117@sfu.ca
 */
#include <iostream>
#include <fstream>
#include <cstdio>  // Needed for NULL
using namespace std;
#pragma once

class LetterRecord{
	private:
		int frequency;        // frequency for a character
        	int index;            // (index-128) is corresdoning to the character in ASCII table
        	bool is_leaf;         // when building a tree, decide if this is a leaf.

	public:
        	LetterRecord* left, *right, *parent;    // define the left right parent nodes
        	int weight;				// define the total weight of two children
        	LetterRecord();				// constructor;
        	int Get_frequency() const;	       	// Desc: Returns the frequency
        	int Get_index() const;			// Desc: Returns the index
        	bool Get_is_leaf() const;		// Desc: Returns if this is a leaf
        	void Set_frequency(unsigned freq);	// Desc: Create frequency setters
        	void Set_index(unsigned length);	// create index setters
        	void Set_is_leaf(bool if_true);		// create boolean setters

		// Desc:  Comparators
	        bool operator<(const LetterRecord &r) const { return weight > r.weight ; };
        	bool operator>(const LetterRecord &r) const { return weight < r.weight; };
        	bool operator<=(const LetterRecord &r) const { return weight >= r.weight ; };
        	bool operator>=(const LetterRecord &r) const { return weight <= r.weight ; };
};
