# Spell_Checker
### Author: Mojgan Mehrabi
### Design and implement a program to spell-check a text document using a given dictionary


# REQUIREMENTS

..*The program will take the name of the dictionary.txt file and the text.txt file to be spell-checked as command line arguments.  You can assume the dictionary file will be formatted as plain text with one word per line.

..*The program will output to screen a list of the incorrectly spelled words.

..*Unusual apitalizations should not be considered incorrect.  Computer, coMpuTer, computeR, computer, and COMPUTER should be treated as correct.

..*Numbers adjacent to words should not be considered incorrect.  Computer, 32computer, and computer54 should be treated as correct.

..*Trailing and leading punctuation should not be considered incorrect.  !computer and "computer" should be treated as correct, but comp.uter should not be treated as correct.

..*When the program starts, the dictionary file should be read into a data structure.  This will initially be a linked list.  A linked list header file is provided.  The linked list implementation should conform to the declarations in the header.

## case1 (To be updated)
*A linked list test application is provided.  Before beginning to work on the spell-checker, the linked list data structure should be implemented and the test application should execute correctly.

A SPELL_CHECK main application is provided.  The function names and behavior in the Spell class should be designed and implemented so that the SPELL_CHECK's main application works correctly.

The data structure and spell-check application should be independent.  We will likely realize that a linked list's  performance is too slow and consider alternative data structures.

1.string, list, vector or similar includes are not permitted. 

2.The spell-check application should have at least the following functions:

3.The loadDict function executes at the start of the program to read the dictionary file into a data structure in memory.

4.The getSizeOfDict function returns the number of words in the dictionary.

5.The getSizeOfDoc function returns the number of words in the document to be check.

The checkDoc function reads the file to be checked, checks each word against the data structure in memory, and outputs to screen a list of incorrectly spelled words.  A searchDict function may be useful here.

An unload function is probably not necessary because list-node-deallocation will likely be handled in the data structure class's destructor.

