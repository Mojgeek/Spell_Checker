#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.h"
#include "config.h"



#endif // !LINKED_LIST_CPP

LinkedList::LinkedList() // default constructor
{
	head = NULL;
	tail = NULL;
	current = NULL;
}

LinkedList::LinkedList(const LinkedList & other) // Copy constructor
{
	head = NULL;
	current = NULL;
	tail = NULL;

	if (other.head != NULL)
	{
		ListNode* temp = other.head; // a pointer that points to the other object's head 
		
		/// I commented out head = temp.  The temp pointer points to addresses of the "other"
		/// object.  We don't want our head to point outside of our object.  This was part of
		/// the problem.  Re-reading the insert function, insert updates the head and tail
		/// as necessary, so no need to do anything here.  -Joe
		//head = temp;

		while (temp != NULL)
		{
			insertAtEnd(temp->data);// character array to the insert function 
			temp = temp->nextPtr;// make the temp to point to the next poinrter
		}

		/// The same here.  I commented out tail = temp.  The insert function updates our head
		/// and tail as neessary.  Setting tail to temp sets our tail to the other objects tail.
		/// This is a "shallow" copy problem. -Joe
		// tail = temp;

		/// While it was unnecessary to reset head and tail here, it was right for us to
		/// set current to our head.  The insert function doesn't adjust current.  
		/// We could rely on the person implementing the class to remember to call
		/// test.setCurrentAtHead(), but it's probably a good idea to do it ourselves
		/// here. -Joe
		current = head;
	}
}

LinkedList & LinkedList::operator=(const LinkedList & other) // Overloaded assignment operator
{
	/// both objects are the same (at the same address). This is
	/// self assignment.  We checked for it here.
	if (this == &other)
	{
		return *this;
		/// myObject = yourObject = theirObject;
		// TODO: insert return statement here
	}

	/// It's possible that our object is empty.  If our object
	/// is not empty, we should delete our current nodes before
	/// attempting to copy something.

	if (this->head != NULL)
	{
		clear();
	}
	/// it's also possible that the other object is empty (meaning
	/// its head is NULL).  If the other object is empty, there's
	/// no need to bother copying anything...
	if (other.head == NULL)
	{
		head = NULL;
		tail = NULL;
		current = NULL;
	}
	else
	{   // we dont want to change the other object's head.
		ListNode *temp = other.head;
		
		/// See my comment in the copy constructor.  The same applies here. -Joe
		//head = temp;

		// Copying the content from other object to our object
		while (temp != NULL)
		{
			this->insertAtEnd(temp->data);
			temp = temp->nextPtr;
		}

		/// See my comment in the copy constructor.  The same applies here. -Joe
		//tail = temp;

		/// Since this assignment operator overload "records over" an existing object,
		/// it's important to properly set our three pointer variables.  The insert
		/// function properly sets head and tail, but current isn't handled there.
		/// If we don't handle it here, current remains NULL (because the clear function
		/// called on line 71 nullifies all three: head, tail, and current. -Joe
		current = head;
	}
	
	return *this;		 
}

LinkedList::~LinkedList()
{
	if (this->head != NULL)
	{
		clear();
	}
}

// Inserting a new node at the end of our object ( this objevt;s linked list)
void LinkedList::insertAtEnd(const char * newDataItem)
{
	ListNode* node = new ListNode; 
   //To copy the entire content of a character array. node->data = copy to , newDataItem = copy from
	strcpy_s(node->data, newDataItem);
	// last node's next pointer which is null
	node->nextPtr = NULL;
	// if the list is previously empty. After the insert operation, the linked list has only one node
	if (tail == NULL)
	{
		head = node;
		tail = node;
	}
	// if the list was not previously empty
	else
	{

		tail->nextPtr = node;
		tail = tail->nextPtr;
		
	}
}

void LinkedList::removeAtFront()
{
	if (this->head == NULL)
	{
		throw logic_error(" The list is empty.Cannot remove at front");
	}
	if (this->head == this->tail)
	{   // deleting the whole node
		delete this->head;
		
		//delete tail;
		this->head = NULL;
		this->tail = NULL;
		this->current = NULL;

	}
	else
	{
		ListNode *temp = head;
		head = head->nextPtr;		
		delete temp;
	}

}

void LinkedList::clear()
{
	ListNode *traverse = head;

	while(traverse != NULL)
	{
		current = traverse;
		traverse = traverse->nextPtr;
		delete this->current;
	}
	head = NULL;
	tail = NULL;
	current = NULL;
}

bool LinkedList::isEmpty() const
{
	return head == NULL;
	/*
	if (this->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

	}
	*/

}

bool LinkedList::atTail() const
{

	return current == tail;
}

void LinkedList::setCurrentAtHead()
{
	if (head == NULL)
		throw logic_error("The list empty. Cannot set current at head.");
	this->current = this->head;
}

void LinkedList::setCurrentAtTail()
{
	if (head == NULL)
		throw logic_error("The list is empty. Cannot set current at tail.");
	this->current = this->tail;
}

void LinkedList::advanceCurrent()
{
	if (head == NULL)
		throw logic_error(" The list is empty. Cannot advance current ");
	//if (this->current == this->tail)
	 if (atTail())
		throw logic_error("Current is the last node in the list. Cannot advance current");
	this->current = current->nextPtr;
}

char * LinkedList::getCurrentData() const

{
  return & (current->data[0]);
}



