#include <iostream>
#include "LinkedList.h"
#include "Spell.h"
#include "config.h"

using namespace std;

#if LIST_TEST
int main(int argc, char *argv[])// commandline parameters
{
	try
	{
		LinkedList test;
		LinkedList test3;

		if (argc < 3) // the number of commandline parameters including the executable name 
			throw logic_error("Command Line arguments must be >= 3.\n");

		for (int i = 0; i < argc - 1; i++)
		{
			test.insertAtEnd(argv[i + 1]);
		}

		test.setCurrentAtHead();

		LinkedList test2 = test;

		while (!test2.atTail())
		{
			cout << test2.getCurrentData() << " ";
			test2.advanceCurrent();
		}

		cout << test2.getCurrentData() << endl;

		test3 = test2;

		test3.removeAtFront();
		test3.setCurrentAtHead();

		while (!test3.atTail())
		{
			cout << test3.getCurrentData() << " ";
			test3.advanceCurrent();
		}
		cout << test3.getCurrentData() << endl;

	}
	catch (logic_error le)
	{
		cout << le.what();
	}

	return 0;
}
#endif // !LIST_TEST

#if SPELL_CHECK
int main(int argc, char *argv[])
{
	try
	{
		if (argc != 3)
			throw logic_error("Give 3 command line arguments: executable dictionaryName fileNameToCheck\n");

		Spell sp(argv[1], argv[2]);
		sp.loadDict();
		cout << "\nSpelling Errors:\n";
		sp.checkDoc();

		cout << "\nWords in dictionary: " << sp.getSizeOfDict() << endl; 
		cout << "Words in document: " << sp.getSizeOfDoc() << endl;
	}
	catch (logic_error le)
	{
		cout << le.what() << endl;
	}

	return 0;
}
#endif // !SPELL_CHECK