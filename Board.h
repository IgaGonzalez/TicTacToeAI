#pragma once
#include<iostream>
#include<string>
#include <stdlib.h> 
using namespace std;
class Board
{
private:
	string board[3][3];
/*	
	      1     2      3
	  +------+------+------+
	 1|[0][0]|[0][1]|[0][2]|
	  +------+------+------+
	 2|[1][0]|[1][1]|[1][2]|
	  +------+------+------+
	 3|[2][0]|[2][1]|[2][2]|
	  +------+------+------+
*/
	
public:
	Board(); //Constructor
	Board(const Board& aux); //Copy Constructor;
	~Board(); //Destructor
	Board& operator = (const Board &aux); //Assignment operator

	void printBoard(); //Print Board
	string checkSymbol(int i, int j); //Check symbol in the parameters
	void placeSymbol(string aux,int i, int j); //Checks if used, and place a symbol
	bool checkWinner();
	bool checkTie();
};

