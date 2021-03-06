// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

// TODO you will need to uncomment the line below
#include <StackQueues.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame() : m_GameEnded(false)
	{
		pole1->push(4);
		pole1->push(3);
		pole1->push(2);
		pole1->push(1);
	}
	
	bool validateMove(int disk, int fromPole, int toPole)
	{
		if (fromPole == 1)   //pole1 
		{
			if (pole1->peek() == disk)
			{
				if (toPole == 2)
				{
					if (pole2->isEmpty() == true || pole2->peek() > disk)
					{
						return true;
					}
				}
				if (toPole == 3)
				{
					if (pole3->isEmpty() == true || pole3->peek() > disk) 
					{
						return true;
					}
				}
			}
		}
		else if (fromPole == 2) //pole2
		{
			if (pole2->peek() == disk)
			{
				if (toPole == 1)
				{
					if (pole1->isEmpty() == true || pole1->peek() > disk)
					{
						return true;
					}
				}
				if (toPole == 3)
				{
					if (pole3->isEmpty() == true || pole3->peek() > disk)
					{
						return true;
					}
				}
			}
		}
		else if (fromPole == 3) //pole3
		{
			if (pole3->peek() == disk)
			{
				if (toPole == 1)
				{
					if (pole1->isEmpty() == true || pole1->peek() > disk)
					{
						return true;
					}
				}
				if (toPole == 2)
				{
					if (pole2->isEmpty() == true || pole2->peek() > disk)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	
	void makeMove(int disk, int fromPole, int toPole)
	{
		if (!validateMove(disk, fromPole, toPole))
		{
			return;
		}
		if (fromPole == 1 && toPole == 2)
		{
			pole1->pop();
			pole2->push(disk);
		}
		if (fromPole == 1 && toPole == 3)
		{
			pole1->pop();
			pole3->push(disk);
		}
		if (fromPole == 2 && toPole == 3)
		{
			pole2->pop();
			pole3->push(disk);
		}
		if (fromPole == 3 && toPole == 2)
		{
			pole3->pop();
			pole2->push(disk);
		}
		if (fromPole == 3 && toPole == 1)
		{
			pole3->pop();
			pole1->push(disk);
		}
		if (fromPole == 2 && toPole == 1)
		{
			pole2->pop();
			pole1->push(disk);
		}
		if (pole1->isEmpty() && pole2->isEmpty())
		{
			cout << "Game over: You won!" << endl;
		}
		else
			cout << "Invalid Move" << endl;

	}

	bool IsGameEnded() { return m_GameEnded; }

	void PrintTowers()
	{
		cout << "1 | " << pole1->toString() << endl;
		cout << "2 | " << pole2->toString() << endl;
		cout << "3 | " << pole3->toString() << endl;
	}

private:
	bool m_GameEnded;
	ArrayBasedStack* pole1 =  new ArrayBasedStack();																																							
	ArrayBasedStack* pole2 = new ArrayBasedStack();
	ArrayBasedStack* pole3 = new ArrayBasedStack();
	ArrayBasedQueue* move = new ArrayBasedQueue();

};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;

	while (!receivedEndToken || game.IsGameEnded())
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "Enter Move " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str());
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
				game.makeMove(diskId, fromId, toId);
			}
		}



	}

    return 0;
}

