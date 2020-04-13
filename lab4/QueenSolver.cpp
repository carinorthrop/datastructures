// QueenSolver.cpp : Defines the entry point for the console application.
//

#include "RecursionList.h"
#include <iostream>
#include <string>

 int main()
{
	ChessBoard chessBoard;

	chessBoard.Solve();

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << chessBoard.PrintQueens(i,j);
		}
		cout << endl;
	}
    return 0;
}

