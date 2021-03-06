#include <list>
#include <vector>
#include <iostream>

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CLASSES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CLASSES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CLASSES_EXPORTS
#define CLASSES_API __declspec(dllexport)
#else
#define CLASSES_API __declspec(dllimport)
#endif

class  CLASSES_API Card
{
public:
	Card(int m_rank);
	virtual ~Card();
	int GetRank() const;
private:
	int m_rank;
};

class CLASSES_API IGame {
public:
	//initialize and shuffle deck 
	IGame();
	virtual ~IGame();
	std::list<const Card *> m_deck;
private:
};

class  CLASSES_API Player
{
public:
	Player();
	virtual ~Player();
	void Draw(IGame * g);
	bool Move(int position);
	void FinishMove(int position, IGame * g, int t);
	void Discard(IGame * g);
	int PrettyPrint();
	bool IsWin();

	std::vector<const Card *> m_hand;
	std::list<const Card *> stack;
private:
};



