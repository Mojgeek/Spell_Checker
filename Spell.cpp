#ifndef SPELL_CPP
#define SPELL_CPP

#include <iostream>
#include <stdio.h>
#include "LinkedList.h"
#include "Spell.h"
#include "config.h"

#if SPELL_CHECK




#endif // !SPELL_CHECK
#endif // !SPELL_CPP

Spell::Spell(char *dictFile, char *doctFile)
{
	int numWordsInDict = 0;

	int numWordsInDoc = 0;

	// assigning the parameters to the data memebers..in order for them to be in scope for the life of the object
	strcpy_s(dictFileName, dictFile);
	strcpy_s(docToCheckFileName, doctFile);

}

void Spell::loadDict()
{   // a file pointer. 
	FILE *fp = 0;
	char tempChar;
	char tempWord[MAX_WORD_LENGTH] = { 0 };

	// C command for openning the file. it is a system commad that takes three param. the first param is the address of the file pointer.
	  // not the address of the file. second is the name of the file. and third is a literal string( file mpode)
	  // r means open for reading. w is open for writing. a= append to the end of the file. r+ = open for reading and writing. 
	fopen_s(&fp, dictFileName, "r");

	if (fp == 0)
	{
		throw logic_error(" Could not open the dictionary file");
	}

	while (true)
	{
		// getc will read one character at a time from a file.
		tempChar = getc(fp);
		if (tempChar == '\n')
		{
			continue;
		}          
		if (tempChar == EOF)
		{
			fclose(fp);
			return;
		}

		for (int i = 0; i < MAX_WORD_LENGTH; i++)
		{
			tempWord[i] = tempChar;
			tempChar = getc(fp);
			if (tempChar == '\n')
			{   // Save the owrd into the data structure -- the end of the linked list 
				dict.insertAtEnd(tempWord);
				numWordsInDict++;
				// a system command that sets the each element of the array to zero.// size of each element times the length of the array
				memset(tempWord, '\0', sizeof(char) * MAX_WORD_LENGTH);

				break;
			}
			if (tempChar == EOF)
			{
				dict.insertAtEnd(tempWord);
				numWordsInDict++;
				fclose(fp);
				return;
			}
		}




	}

}

void Spell::checkDoc()
{
	// a file pointer. To open the file
	FILE *fp = 0;
	char tempChar;
	int i = 0;

	char tempWord[MAX_WORD_LENGTH] = { 0 };
	fopen_s(&fp, docToCheckFileName, "r");

	if (fp == 0)
	{
		throw logic_error(" Could not open the document file");
	}
	while (true)
	{
		tempChar = getc(fp);
		tempChar = tolower(tempChar);
		if ((tempChar>='a' && tempChar<='z') || tempChar=='\'' )
		{  // saving the character to the temword array with a post increment subscription 
			tempWord[i++] = tempChar;
			continue;

		}
		if (tempWord[0] != NULL)
		{
			if (!searchDict(tempWord))
				cout << tempWord<<endl;
			numWordsInDoc++;
			memset(tempWord, '\0', sizeof(char) * MAX_WORD_LENGTH);
			i = 0;
		}

		if (tempChar == EOF)
		{
			fclose(fp);
			return;
		}
		
	 }





}

int Spell::getSizeOfDict()
{
  

	return numWordsInDict;
}

int Spell::getSizeOfDoc()
{

	return numWordsInDoc;
}

bool Spell::searchDict(char * searchTerm)
{
	dict.setCurrentAtHead();
	while (dict.getCurrentData() != NULL)
	{
		if (strcmp(dict.getCurrentData(), searchTerm) == 0)
			return true;

		if (dict.atTail())
			return false;

		dict.advanceCurrent();
	}
}
