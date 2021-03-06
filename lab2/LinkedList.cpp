// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "LinkedList.h"
#include <iostream>

Node::Node(): m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
}

PointerBasedLinkedList::PointerBasedLinkedList()
{

}
/** Returns true  if list is empty, otherwise true */
bool PointerBasedLinkedList::isEmpty() const
{
	if (m_count == 0)
		return true;
	return false;
}
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{  
	Node * newnode = new Node(val);
	newnode->setItem(val);
	Node * temp = m_head;
	while (temp->getNext() != NULL) 
	{
		temp = temp->getNext();
	}
	temp->setNext(newnode);
	newnode->setNext(NULL);
	m_count++;
	return true;
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	Node *prev = m_head;
	Node *current = prev->getNext();
	Node *next = current->getNext();
	while (current->getNext() != NULL)
	{
		if (current->getItem() == val)
		{
			prev->setNext(current->getNext());
			current->setNext(NULL);
			m_count--;
			delete current;
			return true;
		}
		prev = current;
		current = current->getNext();
	}

	return false;
}
/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	Node *next = NULL;
	Node *current = m_head->getNext();

	while (current != NULL)
	{
		next = current->getNext();
		free(current);
		current = next;
	}
	m_head->setNext(nullptr);
	m_count = 0;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	clear();
	m_head = NULL;
	
}

std::string PointerBasedLinkedList::toString() const
{
	Node *prev = m_head;
	std::string newstring = "";

	while (prev->getNext() != NULL)
	{
		prev = prev->getNext();
		newstring += " " + std::to_string(prev->getItem());
	}

	return newstring.substr(1, newstring.length());
}

ArrayBasedLinkedList::ArrayBasedLinkedList()
{
	
}

bool ArrayBasedLinkedList::isEmpty() const
{
	return m_count == 0;
	
}
bool ArrayBasedLinkedList::add(int val)
{
	if (m_count < 10)
	{
		m_values[m_count] = val;
		m_count++;
		return true;
	}
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
	for (int i = 0; i < m_count; i++) 
	{
		if (m_values[i] == val)
		{
			for (int j = i; j < m_count; j++)
			{
				if (j == m_count - 1)
					m_values[j] == NULL;
				else
					m_values[j] = m_values[j + 1];
			}
			m_count--;
			return true;
		}
	}
	return false;
}
void ArrayBasedLinkedList::clear()
{
	int m_values[10];
	m_count = 0;

}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{
	clear();
	// do i need to clean up memory in this?
}

std::string ArrayBasedLinkedList::toString() const
{
	std::string newstring = "";
    
	for (int i = 0; i < 10; i++)
	{
		newstring += " " + std::to_string(m_values[i]);
	}
	newstring += " " + std::to_string(m_values[0]);
	return newstring.substr(1, m_count*2);
}
