#pragma once
#include<iostream>
#include<string>
#include<cassert>
#include <stdlib.h> 
#include"Board.h"
using namespace std;
class Player {
private:	
	string character;
	int i, j;
public:
	Player(); //Default Constructor
	Player(const Player &aux); //Copy Constructor
	virtual ~Player(); //Virtual Destructor
	Player& operator = (const Player& aux); //Assigment operator
	
	Player(string aux); //Parameterized constructor to store value to enter the board

	bool detSymbol(string aux); //True if value is valid. False if not.Determine symbol
	bool detRowColumn(int i, int j);
	virtual void nextMove(Board &aux); // //Determine next move for player. Must be virtual fuction

	string getCharacter();
	void setCharacter(string aux);
	int getRow();
	void setRow(int aux);
	int getColumn();
	void setColumn(int aux);
};