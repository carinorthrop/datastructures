// Classes.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Classes.h"
#include <list>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

Card::Card(int rank)
{
	m_rank = rank;
}

Card::~Card()
{

}

int Card::GetRank() const
{
	return m_rank;
}

Player::Player()
{

}

Player::~Player()
{
	m_hand.clear();
	stack.clear();
}

void Player::Draw(IGame * g)
{
		m_hand.push_back(new Card(g->m_deck.front()->GetRank()));
		g->m_deck.pop_front();
}
bool Player::Move(int position)
{

	if (stack.empty() == true && m_hand.at(position)->GetRank() == 1)
	{
		stack.push_front(new Card(m_hand.at(position)->GetRank()));
		m_hand.erase(m_hand.begin() + position);
		return true;
	}

	if (stack.empty() == false)
	{
		if (stack.front()->GetRank() + 1 == m_hand.at(position)->GetRank())
		{
			stack.push_front(new Card(m_hand.at(position)->GetRank()));
			m_hand.erase(m_hand.begin() + position);
			return true;
		}
	}
	return false;
}

void Player::FinishMove(int position, IGame * g, int t)
{
	//delete one card 
	//t is a 1 card(0) or get rid of everything(1)
	if (t == 1)
	{
		g->m_deck.push_back(new Card(m_hand.at(position)->GetRank()));
		m_hand.erase(m_hand.begin() + position);
	}
	//	delete them all
	if (t == 2) //condition to discard all if chosen during turn 
	{
		while (!m_hand.empty())
		{
			Discard(g);
		}
	}
}

void Player::Discard(IGame * g)
{
	g->m_deck.push_back(new Card(m_hand.front()->GetRank()));
	m_hand.erase(m_hand.begin());
}


int Player::PrettyPrint()
{
	//print this out after each turn to keep track of hand and stack
	int name;
	std::cout << "Your Hand:" << " ";
	for (const Card * c : m_hand)
	{
		name = c->GetRank();
		cout << name << " ";
		//to string problem convert to do a card rather than the integer 
	}

	std::cout << "Your Stack:" << " ";
	for (const Card* c : stack)
	{
		name = c->GetRank();
		cout << name << " ";
	}
	return 1;
}

bool Player::IsWin()
{
	//if (!stack.empty() && stack.front()->GetRank() == 13)
	//{
	//	return true;
	//}
   if (stack.size() == 13)
	{
		return true;
	}
	else
	{
		return false;
	}
}

IGame::IGame()
{
	int pos = 0;
	for (int s = 0; s < 4; s++) {
		for (int rank = 1; rank <= 13; rank++)
		{
			m_deck.push_back(new Card(rank));
			pos++;
		}
	}
	std::vector<const Card *> temp(m_deck.begin(), m_deck.end());
	std::random_shuffle(temp.begin(), temp.end());
	std::copy(temp.begin(), temp.end(), m_deck.begin());
}

IGame::~IGame()
{
	m_deck.clear();
}




