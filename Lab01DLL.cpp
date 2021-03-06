// Lab01DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Lab01DLL.h"


// This is the constructor of a class that has been exported.
// see Lab01DLL.h for the class definition
Card::Card(suit_t suit, int rank): m_suit(suit), m_rank(rank), m_dealt(false)
{
    
}


Deck::Deck()
{
	init_deck();
}

Card Deck::GetCard(int index)
{
	return m_deck[index];
}

Card Deck::GetCard(suit_t suit, int rank)
{
	for (int i = 0; i < m_deck.size(); i++)
	{
		if (m_deck[i].GetSuit() == suit && m_deck[i].GetRank() == rank)
			return m_deck[i];
	}
	throw "NIY";
}

/**
* Initialize the deck so that all cards exist, and are not yet dealt.
*/
void Deck::init_deck() 
{
	int pos = 0;
	for (int s = 0; s < 4; s++) {
		for (int rank = 1; rank <= 13; rank++) 
		{
			m_deck.push_back(Card((suit_t), rank));
			pos++;
		}
	}
}

BlackJackHand::BlackJackHand()
{
	
}

void BlackJackHand::AddCard(Card c)
{
	m_hand.push_back(c);
}

int BlackJackHand::ScoreHand()
{
    int score = 0;
	int rank = 0;
	for (int i = 0; i < m_hand.size(); i++)
	{
		rank = m_hand[i].GetRank();

		if (rank > 10 && rank < 13)
			rank = 10;
		if (rank == 1)
		{
			if (score + 11 > 21)
				rank = 1;
			else
				rank = 11;
		}
		score = score + rank;
	}

	if (score > 21)
		return -1;
	else
		return score;
}


