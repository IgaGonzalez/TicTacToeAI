#include "Board.h"
#include<iostream>
using namespace std;

Board::Board()
{
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			board[i][j] = " ";
}

Board::Board(const Board & aux)
{
	//copy
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			board[i][j] = aux.board[i][j];
}

Board::~Board()
{
	//delete[] &board;
}

Board & Board::operator=(const Board &aux)
{
	if (this == &aux) //Self assigment guard
		return *this;
	//copy
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			board[i][j] = aux.board[i][j];
	return *this;

}

void Board::printBoard()
{
	cout << "+---+---+---+\n";
	cout << "| " << board[0][0] << " | " << board[0][1] << " | "<<board[0][2]<<" |\n";
	cout << "+---+---+---+\n";
	cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |\n";
	cout << "+---+---+---+\n";
	cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |\n";
	cout << "+---+---+---+\n";
}

string Board::checkSymbol(int i, int j)
{
	return board[i][j];
}

void Board::placeSymbol(string aux, int i, int j)
{
	board[i][j] = aux;
}

bool Board::checkWinner()
{
	// Left to Right same value
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != " ")
		return true;
	else if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != " ")
		return true;
	else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != " ")
		return true;

	// upwards & downwards same value
	else if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != " ")
		return true;
	else if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != " ")
		return true;
	else if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != " ")
		return true;

	// Diagonal same value
	else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != " ")
		return true;
	else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != " ")
		return true;
	else
		return false;
}

bool Board::checkTie()
{
	for (int i = 0; i < 3;i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == " ")
				return false;
	return true;
}
