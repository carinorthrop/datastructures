// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LAB01DLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LAB01DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB01DLL_EXPORTS
#define LAB01DLL_API __declspec(dllexport)
#else
#define LAB01DLL_API __declspec(dllimport)
#endif

#include <vector>

// Define a type that represends the 4 suits of a deck of cards
enum suit_t {
	HEARTS,
	SPADES,
	DIAMONDS,
	CLUBS
};

// This class is exported from the Lab01DLL.dll
class LAB01DLL_API Card {
public:
	Card(suit_t suit, int rank);

	suit_t GetSuit()
	{
		return m_suit;
	}

	int GetRank()
	{
		return m_rank;
	}

private:
	Card(); // Declaring this a private and not providing an
			// implementation to prevent default constructor
	//  Here to prove point copy constructor is being called Card(const Card&); // copy constructor
	// Card suit
	suit_t m_suit;
	// 1 = Ace
	// 2 - 10, number card of corresponding value
	// 11 = jack, 12 = queen, 13 = king
	int m_rank;
	bool m_dealt;
};

// A single, standard deck of 52 playing cards.
const int DECK_SIZE = 52;
// This class is exported from the Lab01DLL.dll
class LAB01DLL_API Deck {
public:
	Deck();

	// Get Card based upon index of the private vector
	Card GetCard(int index);

	// Get specific Card that matches suit and rank
	// Invalid combinations or cards that are missing will throw an exception
	Card GetCard(suit_t suit, int rank);

private:
	void init_deck();
	std::vector<Card> m_deck;
};

class LAB01DLL_API BlackJackHand
{
	public:
		BlackJackHand();

		// Add card to hand to be scored
		void AddCard(Card c);

		//  Basic black rules, over 21 is a bust and -1 is returned
		// Aces can be 1 or 11, face cards are 10
		int ScoreHand();

	private:
		std::vector<Card> m_hand;
};

