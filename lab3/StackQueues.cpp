// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "StackQueues.h"
#include <iostream> 
using namespace std;

     ArrayBasedStack::ArrayBasedStack() 
    { 
		 top = -1; 
	}
	bool ArrayBasedStack::push(int value)
	{
		if (top == value)
		{
			cout << "\nThe stack is full " << endl;
			return false;
		}
		top++;
		stack_array[top] = value;
		return true;
	}
	bool ArrayBasedStack::pop()
	{
		if (top == -1)
		{
			cout << "\nThe stack is empty" << endl;
			return false;
		}
		top--;
		return true;
	}
	int ArrayBasedStack::peek()
	{
		if (this->isEmpty())
		{
			cout << "Invalid Move" << endl;
			throw "ADT is emtpy";	
		}
		else
		{
			cout << "Invalid Move" << endl;
			return stack_array[top];
		}
	}
	int ArrayBasedStack::isLength ()
	{
		return top;
    }
	bool ArrayBasedStack::isEmpty() const
	{
		return (top == -1);
		return true;
	}
	string ArrayBasedStack::toString()
	{
		std::string newstring = "";

		for (int i = top; i >= 0; i--)
		{
			newstring += " " + std::to_string(stack_array[i]);
		}
		return newstring;
	}
	ArrayBasedStack::~ArrayBasedStack()
	{
		top = NULL;
	}
	
		bool ArrayBasedQueue::isEmpty() const
		{
			if (front == 0 && back == 0)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		//inserts an element into the back of the queue
		bool ArrayBasedQueue::enQueue(string val)
		{
			int j = back;
			while (j != 0) 
			{
				queue_array[j] = queue_array[j - 1];
				j--;
			}
			queue_array[0] = val;
			back++;
			return true;
		}

		// removed an element from the front of the queue
      bool ArrayBasedQueue::deQueue()
		{
			if (isEmpty())
			{
				cout << "\nThe queue is empty" << endl;
				return false;
			}
			    if (size == front + 1)
				{
					front = 0;
				}
				else
				{
					back--;
					return true;
				}
		}
string ArrayBasedQueue::peekFront()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
    	return queue_array[back - 1];
	}
}
ArrayBasedQueue::ArrayBasedQueue()
{
}
ArrayBasedQueue::~ArrayBasedQueue()
{
}

