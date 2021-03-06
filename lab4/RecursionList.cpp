// RecursionList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "RecursionList.h"
#include <iostream>

int FactorialByLoop::CalculateFactorial(int num)
{
	int factorial = 1;
	for (int i = 1; i <= num; i++)
	{
		factorial = factorial * i;
	}
	return factorial;
}

int FactorialByRecursion::CalculateFactorial(int num)
{
	int fact = 1;
	{
		if (num == 0)
			return 1;
		else
			return num * FactorialByRecursion::CalculateFactorial(num - 1);
	}
}

int FactorialByStack::CalculateFactorial(int n)
{
		std::stack<int> num;
		int s = 1;
		for (int i = 1; i <= n; i++)
		{
			num.push(i);
		}
		while (!num.empty())
		{
			s *= num.top();
			num.pop();
		}
		return s;
}


extern void SimpleExceptionMethod(int i)
{
	MyException expection;
	if (i == 1)
		throw expection;
	if (i == -1)
		throw expection;

}
char const* MyException::what() const throw()
{
	return "MyException";
}

bool ChessBoard::CheckSafeQueens(int row, int column)
{
	int i;
	int j;
	for (i = 0; i < column; i++)
	{
		if (m_board[row][i])
		{
			return false;
		}
	}

	for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
	{
		if (m_board[i][j])
		{
			return false;
		}
	}

	for (i = row, j = column; j >= 0 && i < 8; i++, j--)
	{
		if (m_board[i][j])
		{
			return false;
		}
	}
	return true;
}

bool ChessBoard::PlaceQueens(int column)
{
	if (column > 7)
		return true;
	for (int i = 0; i < 8; i++)
	{
		if (CheckSafeQueens(i, column))
		{
			m_board[i][column] = 1;

			if (PlaceQueens(column + 1) == true)
			{
				return true;
			}
			m_board[i][column] = 0;
		}
	}
	return false;
}

int ChessBoard::PrintQueens(int i, int j)
{
	return m_board[i][j];
}

