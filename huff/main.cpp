/*
 * main.cpp
 *
 * Class Definition: read a bit from a file and to write a bit or sequence of bits to a file.
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
#include <cstdio>  // Needed for NULL
#include "LetterRecord.h"
#include "BitStream.h"
#include "HuffmanTree.h"
#include <string> // for string class
using namespace std;

int main (int argc, char *argv[]){
	if (argc != 4){
		cout<<"Input is invalid \n";
	    	return 0;
	}

	if (argv[1][0] == '-' && argv[1][1] == 'c'){
		// We assume argv[w] is a filename to open
		ifstream in_file ( argv[2] );
  		// check to see if file can be opend
  		if ( !in_file.is_open() ){
			cout<<"Failure to open the file\n";
    			return 0;
		}
  		else{   // empty file
      			if (in_file.peek() == std::ifstream::traits_type::eof()){
        			cout << "The file is empty. No need to compress"<<endl;
        			return 0;
      			}
						//get length for input and out put file
						in_file.seekg(0, std::ios_base::end);
						int len = in_file.tellg();
      			in_file.close();		// everything good, close the file
      			FrequencyCounter text_comp;	// read and build the Frequency table
      			text_comp.readfrequency(argv[2]);

      			HuffmanTree Tree;		// build the tree
      			LetterRecord* root = Tree.BuildHuffTree(text_comp);
						//if length of inout file is 1
						if(len == 1){
							LetterRecord* top = new LetterRecord;      // create a dynamic Node to combine node1 and node2, and it is not a leaf;
		        	top->Set_is_leaf(false);                   // Combined Node is not leaf, and need to combine the weight;
							top->left = root;
							root->parent = top;
							root = top;
						}

      			string a ="";
      			Tree.StoreDigit(root, a, text_comp.DigitHouse);

      			//write into the output file
      			comp_write_file(argv[3],text_comp,argv[2]);

      			//print out the size of file
      			ifstream input_file ( argv[2]);
      			ifstream output_file ( argv[3] );

      			//get length for input and out put file
      			input_file.seekg(0, std::ios_base::end);
      			size_t input_file_length = input_file.tellg();
      			output_file.seekg(0, std::ios_base::end);
      			size_t output_file_length = output_file.tellg();

      			//print message for size
     			cout << argv[2] <<" -> " << input_file_length << " bytes"<<endl;
      			cout << argv[3] <<" -> " << output_file_length << " bytes"<<endl;
      			//warning message
      			if(output_file_length > input_file_length){
        			cout <<"*** Size of compressed file > size of source file ***" <<endl;
      			}
      			//close file
      			output_file.close();
      			input_file.close();
  		}
	}

	// if user input a decompression operator
	else if (argv[1][0] == '-' && argv[1][1] == 'd'){
		// We assume argv[w] is a filename to open
  		ifstream in_file (argv[2]);

    		// check to see if file can be opend
    		if ( !in_file.is_open() ){
			cout<<"Failure to open the file\n";
      			return 0;
		}
    		else {
        		if (in_file.peek() == std::ifstream::traits_type::eof()){
          			cout << "The file is empty. No need to compress"<<endl;
          			return 0;
        		}
        		// read and build the Frequency table
        		FrequencyCounter text_decomp;
        		int ftable[256];
        		in_file.read((char *)ftable, sizeof(int)*256);
        		for (int i=0;i<256;i++){
            			text_decomp.freqency_count[i] = ftable[i];
        		}
       			// build the tree
        		HuffmanTree Tree;
        		LetterRecord* root = Tree.BuildHuffTree(text_decomp);
        		int total_freq =0;         //total Frequency is used to count the total number of frequency
        		//count total frequency
        		for(int i = 0 ;i <256; i++){
            			total_freq += text_decomp.freqency_count[i];
        		}
						//if there is only one character
						if(total_freq  == 1){
							LetterRecord* top = new LetterRecord;      // create a top
							top->Set_is_leaf(false);                   // let one character is 0;
							top->left = root;
							root->parent = top;
							root = top;
						}
						LetterRecord* temp = root;									//create a temp pointing to root
        		// read the 0/1-string from the rest of the text
        		decomp_restore_file(in_file,argv[3],root,temp,total_freq);
    		}
  	}
}
