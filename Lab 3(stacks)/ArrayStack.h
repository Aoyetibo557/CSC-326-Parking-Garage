
/** ADT stack: Array-based implementation.
 Listing 7-1
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackInterface.h"

const int MAX_STACK = 5;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:	
	ItemType items[MAX_STACK]; // Array of stack items
	int top;              // Index to top of stack
	
public:
	 ArrayStack();             // Default constructor
	 bool isEmpty() const;
	 bool isFull() const;
	 bool push(const ItemType& newEntry);
	 bool pop();
	 ItemType peek() const;	
}; // end ArrayStack

#include "ArrayStack.cpp"
#endif
