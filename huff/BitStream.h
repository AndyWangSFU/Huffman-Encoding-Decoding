/*
 * BitStream.h
 *
 * Class Definition: read a bit from a file and to write a bit or sequence of bits to a file.
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
#include <string> // for string class
using namespace std;
#pragma once



 //Pre:  LetterString is text string reading from text file and it is not empty, StringLength
 //	 is the length of text String. DigitHouse is digit sequence corresdoning to 256 characters in ASCII
 //Desc: Return a string that convert the sequence of a whole text to the sequence of a digit string

void comp_write_file(string filename,FrequencyCounter& text_comp, string read_file){
	// open an output file
	ofstream OutFile;
	OutFile.open (filename);
	//open an infput file
	ifstream InFile;
	InFile.open (read_file);

	OutFile.write((char*)&(text_comp.freqency_count), sizeof(int)*256);
	// write thr frequency table into
 	char x=0;               	// create a unsigned character to write into file
    	string input_0_1 = "";          // a string to store converting 0/1 digits in order to write into file

    	// get the length of the text file
    	InFile.seekg (0, ios::end);
    	int length = InFile.tellg();
			// cout << length<<"here!!"<<endl;
	//return to begining
    	InFile.seekg (0, ios::beg);
    	//convert the sequence of a whole text to the sequence of a digit string
    	for(int i = 0; i < length;i++){
        	char cha = InFile.get();
					int index = cha;
        	input_0_1.append(text_comp.DigitHouse[128+index]);
		while(input_0_1.length() >=8){          // if the string has greater than or equal to 8 0/1-string
          		for (int j = 0; j< 8; j++){
              			if(input_0_1[j] == '1'){    //if this "1" chracter write 1
                			x = x|(1<<j);
              			}
          		}
          		input_0_1.erase (0,8);          // erase the first  8 positions of 0/1-string
          		OutFile << x;                   // write the binary into file
          		x=0;                            // initialize x in order to write another byte
        	}
    	}

	if( input_0_1.length() < 8 && input_0_1.length()  > 0){
    		x=0;
    		for(int i =0; i < input_0_1.length(); i++){
          		if(input_0_1[i] == '1'){        //if this "1" chracter write 1
            			x = x|(1<<(i));
          		}
      		}
    	// if length < 8
		OutFile.put(x);
	}
	InFile.close();
	OutFile.close();
}



//Pre:    the string input_0_1 is not empty, root and temp is not null
//Desc:   the function will restore the compressed file and write into recover_filename
//Post:   the compressed file is decompressed
bool  write_restore_file(ofstream& RestoreFile, LetterRecord* root, LetterRecord* temp, int& total_freq){
        // in case of last 8 digit that have useless "0"
        // stop the recursion
        // base case
        if(total_freq==0){
        	RestoreFile.close();                               //close the file
            	return 1;
	}

        if(temp->Get_is_leaf()){
          	//cout << total_freq <<endl;

            	total_freq--;                                      // total frequency -1
            	char restore_char = temp->Get_index()-128;         // recover the character
            	RestoreFile.put(restore_char);
                //go back to the root and find the next character;
            	return 1;
        }

	return 0;
}


//Pre:    the in_file is not empty, root and temp is not null
//Desc:   the function will restore the compressed file and write into recover_filename
//Post:   the compressed file is decompressed

void decomp_restore_file(ifstream& in_file, string recover_filename, LetterRecord* root, LetterRecord* temp, int& total_freq){
      char input;
      // OPEN a file for restore file
      ofstream RestoreFile ;
      RestoreFile.open(recover_filename);
      while(in_file.get(input)){
      	      // if the total frequency is greater than 0
              for(int i = 0; i < 8; i++){
              //if the total frequency is greater than zero
              		if(total_freq>0){
                      		if((input >> i) & 1){
                            		temp = temp->right;
              				if(write_restore_file(RestoreFile, root,temp,total_freq))
                                   		temp = root;
				}
                      		else{
                            		//shift to the left subtree
                            		temp = temp->left;
                            		if(write_restore_file(RestoreFile, root,temp,total_freq)){
                                  	temp = root;
                            		}
                      		}
              		}
                  	else{
                    		break;
                  	}
              }
     }
      //clsoe the file
      in_file.close();
}
