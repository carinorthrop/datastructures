// heapsDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "heapsDLL.h"
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

Node::Node() : m_value(0), m_next_right(nullptr), m_next_left(nullptr)
{
}

Node::Node(int val) : m_value(val), m_next_right(nullptr), m_next_left(nullptr)
{

}


void Node::setItem(const int& val)
{
	m_value = val;
}

void Node::setNextLeft(Node * nextNodePtr)
{
	m_next_left = nextNodePtr;
}

void Node::setNextRight(Node * nextNodePtr)
{
	m_next_right = nextNodePtr;
}


int Node::getItem() const
{
	if (m_value == 0)
	{
		return 0;
	}
	return m_value;
}

Node * Node::getNextLeft() const
{
	if (m_next_left == NULL)
		return nullptr;
	return m_next_left;
}

Node * Node::getNextRight() const
{
	if (m_next_right == NULL)
		return nullptr;
	return m_next_right;
}

Node::~Node()
{
	delete m_next_left;
	delete m_next_right;
}

//heap stuff
void heap::insert(int inputNode)
{
	a.push_back(inputNode);
	balanceHeap(a.size());
}
int heap::remove(int findThis)
{
	return 0;
}

//based on algorithm from geeksforgeeks.com
void heap::balanceHeap(int size)
{
	int i = a.size() - 1;
	if (i >= 0)
	{
		while (i != 0 && a[(i - 1) / 2] > a[i])
		{
			swap(a[i], a[(i - 1) / 2]);
			i = (i - 1) / 2;
			if (i == 0)
			{
				break;
			}
		}
	}

}


void heap::printHeap()
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ", ";
	}
}

//queue stuff
void queue::insert(int input)
{
	pqueue.push_back(input);
}

int queue::remove(int find)
{
	//int 
	//while ()
	return 0;
}

void queue::printQueue()
{
	
	while (!pqueue.empty())
	{
		cout << " " << pqueue[0] << endl;
		pqueue.erase(pqueue.begin());
	}	
}
