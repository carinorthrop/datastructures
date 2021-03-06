// 13Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Classes.h"

using namespace std;

int main()
{
	IGame *game = new IGame();
	Player *Play1 = new Player();
	Player *Play2 = new Player();
	Player *p;

	int choice = 0;
	int position = 0;
	int currentplayer = 1;

	while ((Play1->IsWin() == false) && (Play2->IsWin() == false))
	{
		//player 1 loop
		while (currentplayer == 1 && Play1->IsWin() == false)
		{
			cout << "Player 1: Please select from menu:" << endl;
			cout << "1: Draw" << endl; //  continues turn 
			cout << "2: Redraw 5 new cards" << endl; //ends turn 
			cout << "3: Discard - 1 card" << endl; //ends turn 
			cout << "4: Move card to stack" << endl; // continues turn 
			cout << "5: End turn" << endl; //ends turn 
			Play1->PrettyPrint();
			cin >> choice;

			if (choice == 1)
			{
				if (Play1->m_hand.size() <= 5)
				{
					Play1->Draw(game);
				}
				else
				{
					cout << "Cannot have more than 6 cards in hand, please select another option" << endl;
				}
				//continues turn
			}
			if (choice == 2)
			{
				Play1->FinishMove(position, game, 2);
				Play1->Draw(game);
				Play1->Draw(game);
				Play1->Draw(game);
				Play1->Draw(game);
				Play1->Draw(game);
				currentplayer = 2;
				cout << "Your turn has ended" << endl;
				//ends turn 

			}
			if (choice == 3)
			{
				cout << "What is the position of the card you would like to discard? (count starts at 0)" << endl;
				cin >> position;
				Play1->FinishMove(position, game, 1);
				currentplayer = 2;
				cout << "Your turn has ended" << endl;
				//ends turn
			}

			if (choice == 4)
			{
				cout << "What is the position of card you would like to move to stack? (count starts at 0)" << endl;
				cin >> position;
				Play1->Move(position);
				//continues turn 
			}

			if (choice == 5)
			{
				currentplayer = 2;
				cout << "Your turn has ended" << endl;
				//ends turn
			}
		}

		//player 2 loop
		while (currentplayer == 2 && Play2->IsWin() == false)
		{
			cout << "Player 2: Please select from menu:" << endl;
			cout << "1: Draw" << endl; //  continues turn 
			cout << "2: Redraw 5 new cards" << endl; //ends turn 
			cout << "3: Discard - 1 card" << endl; //ends turn 
			cout << "4: Move card to stack" << endl; // continues turn 
			cout << "5: End turn" << endl; //ends turn 
			Play2->PrettyPrint();
			cin >> choice;

			if (choice == 1)
			{
				if (Play2->m_hand.size() <= 5)
				{
					Play2->Draw(game);
				}
				else
				{
					cout << "Cannot have more than 6 cards in hand, please select another option" << endl;
				}
				//continues turn
			}
			if (choice == 2)
			{
				Play2->FinishMove(position, game, 2);
				Play2->Draw(game);
				Play2->Draw(game);
				Play2->Draw(game);
				Play2->Draw(game);
				Play2->Draw(game);
				currentplayer = 1;
				cout << "Your turn has ended" << endl;
				//ends turn 

			}
			if (choice == 3)
			{
				cout << "What is the position of the card you would like to discard? (count starts at 0)" << endl;
				cin >> position;
				Play2->FinishMove(position, game, 1);
				currentplayer = 1;
				cout << "Your turn has ended" << endl;
				//ends turn
			}

			if (choice == 4)
			{
				cout << "What is the position of card you would like to move to stack? (count starts at 0)" << endl;
				cin >> position;
				Play2->Move(position);
				//continues turn 
			}

			if (choice == 5)
			{
				currentplayer = 1;
				cout << "Your turn has ended" << endl;
				//ends turn
			}
		}
	}

	cout << "You have won!" << endl;

	delete Play1;
	delete Play2;
	delete game;

}


