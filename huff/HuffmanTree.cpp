/*
 * HuffmanTree.cpp
 *
 * Class Definition: HuffmanTree.cpp implement the function provided in HuffmanTree.h
 *
 *
 * Spring 2019 / CMPT-225 D200
 * Created on: Mar 19, 2019
 * Author: Perry Wu  301273743 - plwu@sfu.ca
	   Andy Wang 301329429 - zwa117@sfu.ca
 */
#include <iostream>
#include <fstream>
#include <string> // for string class
#include "HuffmanTree.h"
#include "FrequencyCounter.h"
#include "LetterRecord.h"
#include "PriorityQueue.h"
#include <cstdio>  // Needed for NULL




//pre: the frequency_table is not empty.
//Desc: the function uses to create a node and build a tree
//Pos:  return the pointer node of tree
LetterRecord* HuffmanTree::BuildHuffTree(FrequencyCounter& frequency_table){
    	// define the priority queue
	PriorityQueue<LetterRecord> HuffTree;

    	//get the requency of each character and put
    	for(int i = 0; i < 256 ;i++){
      		// only enqueue those appearing at least one time
      		if(frequency_table.getter(i)>0){
        		LetterRecord* node = new LetterRecord;          // create a dynamic Node
        		node->Set_index(i);                             // set the index : (index-128) is corresdoning to the character in ASCII table
        		node->Set_frequency(frequency_table.getter(i)); // record its frequency into node
        		node->Set_is_leaf(true);                        // record the node if its leaf
        		node->weight = frequency_table.getter(i);       // weight of each single node
        		HuffTree.enqueue(*node);                        // enqueue into the PriorityQueue
		}
	}
      	//using while loop to build a tree
    	while(!HuffTree.isEmpty()){
		LetterRecord* combine_node1 = HuffTree.dequeue();
            	// test if the Priority Queue has only one node
            	// if yes, then it is the node of the root
              	if(HuffTree.isEmpty()){
                	return combine_node1;
                }
        	LetterRecord* combine_node2 = HuffTree.dequeue();
       		LetterRecord* combine_node1_and_node2 = new LetterRecord;      // create a dynamic Node to combine node1 and node2, and it is not a leaf;
        	combine_node1_and_node2->Set_is_leaf(false);                   // Combined Node is not leaf, and need to combine the weight
        	combine_node1_and_node2->weight = combine_node1->weight + combine_node2->weight; 

        	// build the connection between left right childs and their parent
        	combine_node1_and_node2->left = combine_node1;
        	combine_node1_and_node2->right = combine_node2;
        	combine_node1->parent = combine_node1_and_node2;
        	combine_node2->parent = combine_node1_and_node2;
	
        	// enqueue a new combination node of node1 and node2 into PriorityQueue
           	HuffTree.enqueue(*combine_node1_and_node2);
        }
}


//pre:  HuffTree is builded
//Desc: Create a digit sequence to represent the character
//Pos:  Digits are created
void HuffmanTree::StoreDigit(LetterRecord* root, string digit, string DigitHouse[]){
	// if this is leaf
      	if(root->Get_is_leaf() == true ){
        	DigitHouse[root->Get_index()] = digit;      	  // assign the digit string to the DigitHouse inorder to store the digit sequence;
          	return;
      	}

      	string temp = digit;
      	if(root->left){
        	temp = temp.append("0");                          //add digit sequence
        	StoreDigit(root->left, temp, DigitHouse);
      	}

      	temp = digit;
      	if(root->right){
        	temp = temp.append("1");                          //add digit sequence
        	StoreDigit(root->right,temp,  DigitHouse);
      	}
}
