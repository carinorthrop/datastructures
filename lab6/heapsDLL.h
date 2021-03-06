// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the HEAPSDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// HEAPSDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef HEAPSDLL_EXPORTS
#define HEAPSDLL_API __declspec(dllexport)
#else
#define HEAPSDLL_API __declspec(dllimport)
#endif

#include <list>
#include <vector>
#include <algorithm>
#include "stdafx.h"

using namespace std;

// This class is exported from the dll


class HEAPSDLL_API Node { 
private:
	Node * m_next_left;
	Node * m_next_right;

public:
	int m_value;
	Node();
	Node(int val);
	void setItem(const int& val);
	void setNextLeft(Node* nextNodePtr);
	void setNextRight(Node* nextNodePtr);
	int getItem() const;
	Node * getNextLeft() const;
	Node * getNextRight() const;
	virtual ~Node();
};

class HEAPSDLL_API heap {
public:
	void insert(int inputNode);
	int remove(int findThis);
	void balanceHeap(int size);
	void printHeap();
	vector<int> a;
};

class HEAPSDLL_API queue {
public:
	void insert(int input);
	int remove(int find);
	void printQueue();
	int back = 0;
	vector<int> pqueue;
};

extern HEAPSDLL_API int nheapsDLL;

HEAPSDLL_API int fnheapsDLL(void);
