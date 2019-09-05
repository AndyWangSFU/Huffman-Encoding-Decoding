all:	huff

huff:	main.o PriorityQueue.h Node.h FrequencyCounter.h HuffmanTree.h LetterRecord.h LetterRecord.o HuffmanTree.o EmptyDataCollectionException.o BitStream.h
	g++ -Wall -std=c++11 -o huff main.o LetterRecord.o HuffmanTree.o EmptyDataCollectionException.o

main.o:	main.cpp PriorityQueue.h Node.h Queue.h FrequencyCounter.h HuffmanTree.h LetterRecord.h EmptyDataCollectionException.h BitStream.h
	g++ -c main.cpp

LetterRecord.o:	LetterRecord.cpp LetterRecord.h
	g++ -c LetterRecord.cpp

HuffmanTree.o:	HuffmanTree.cpp HuffmanTree.h FrequencyCounter.h PriorityQueue.h LetterRecord.h
		g++ -c HuffmanTree.cpp

EmptyDataCollectionException.o:	EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f huff *.o
