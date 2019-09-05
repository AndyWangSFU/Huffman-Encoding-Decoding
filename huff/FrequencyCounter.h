/*
 * FrequencyCounter.h
 *
 * Class Definition: FrequencyCounter.h is used to count the frequency of each
 * 									character reading from the text.file
 *
 *
 * Spring 2019 / CMPT-225 D200
 * Created on: Mar 19, 2019
 * Author: Perry Wu  301273743 - plwu@sfu.ca
	   Andy Wang 301329429 - zwa117@sfu.ca
 */

#include <string> // for string class
#include <cstdio>  // Needed for NULL
// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
using namespace std;
#pragma once

class FrequencyCounter {
	
	public:
		int freqency_count[256];     	//create an array to count frequency from the text (should be "frequency")
		string DigitHouse[256];		//digit sequence corresponding to characters
		char symble;			//symble to read the  character from file (should be "symbol")

	        // Desc: read the Frequency from the text file.
		// Post: return a text string
		void readfrequency(string filename){
			ifstream InputFile;
			InputFile.open(filename);
			char symble;
			// initialize array to be 0
			for(int i = 0; i< 256;i++){
				freqency_count[i]=0;
			}
			while(InputFile.get(symble)){           // read the character
				int i = symble; 		// index to calculate
				freqency_count[i+128]++;        // count the frequency and store in array
			}
			InputFile.close();
			return;					
		}

	        // Desc: Returns the frequency corresdoning to its character. (O(1))
		int getter(int index){
			return freqency_count[index];
		}
}; // Event
