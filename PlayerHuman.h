#pragma once
#include "Player.h"
#include"Board.h"
#include <stdlib.h> 
#include<string>
using namespace std;

class PlayerHuman :
	public Player
{
protected:
	string character;
	int row, column;
public:
	PlayerHuman(); //Default Constructor
	PlayerHuman(const PlayerHuman& aux); //Copy Constructor
	~PlayerHuman(); //Destructor
	PlayerHuman& operator = (const PlayerHuman& aux); //Assigment operator
	void nextMove(Board& aux);
	bool checkSpot(Board & aux, int i, int j);
	PlayerHuman(string aux);
};

