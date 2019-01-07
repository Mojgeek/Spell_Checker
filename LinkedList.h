#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <stdio.h>
#include "config.h"

using namespace std;

class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList& other); // Copy Constructor
	LinkedList& operator=(const LinkedList& other); // overloaded assignment opertor
	~LinkedList();

	// Insert a node at the end of the linkedList
	void insertAtEnd(const char* newDataItem);
	// Remove a node at front of the list
	void removeAtFront();
	void clear();
	bool isEmpty() const;
	// boolean function which returns true if the current pointer is pointing to the tail
	bool atTail() const;
	// sets the current pointer to the head
	void setCurrentAtHead();
	// sets the current pointer to the tail
	void setCurrentAtTail();
	// increments the pointer
	void advanceCurrent();
	// it returns the memory address of the current node  
	char* getCurrentData() const;

private:
	struct ListNode
	{
		char data[MAX_WORD_LENGTH] = { 0 }; // Sets every position in the array to null
		ListNode* nextPtr;
	};

	ListNode* head;
	ListNode* tail;
	ListNode* current;
};

#endif // !LINKED_LIST_H
