#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "LinkedList.h"
#include "config.h"

using namespace std;

#if SPELL_CHECK

class Spell
{
public:
	// constructor that takes in two pointer characters, one for the dictionary file and the other is 
	// the file that it reads
	Spell(char*, char*); 
	// function for loading the dictionary
	void loadDict();
	// function to read in the documents to be checked and compare it against all the words in the dictionary
	// if the word is spelled correctly it outputs the word as it is, otherwise it announces them as errors
	void checkDoc();
	// Word count  for the dictionary file
	int getSizeOfDict();
	// word count for the document file
	int getSizeOfDoc();
	// boolean function that takes in a pointer character that points to the position zero of the character array
	// stored in each node, it retruns true if it finds the word in the dictionary, otherwise it returs false
	bool searchDict(char*);

private:

	LinkedList dict;
	// the name of the dictionary file name
	char dictFileName[FILE_NAME_LENGTH];
	// the name of the text file document to be checked
	char docToCheckFileName[FILE_NAME_LENGTH];
	// the number of words in teh dictionary
	int numWordsInDict;
	// number of the words in the document
	int numWordsInDoc;
};

#endif // !SPELL_CHECK
#endif // !SPELL_H
