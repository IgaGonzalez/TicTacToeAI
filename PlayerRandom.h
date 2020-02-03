#pragma once
#include "Player.h"
#include"AI.h"
#include"Board.h"
#include <stdlib.h>
#include<string>
#include<ctime>
using namespace std;
class PlayerRandom :
	public Player
{
private:
	string character;//Need to change after  in case computer begins
	int row, column;
public:
	PlayerRandom(); //Default Constructor
	PlayerRandom(string aux);
	PlayerRandom(const PlayerRandom& aux); //Copy Constructor
	~PlayerRandom(); //Destructor
	PlayerRandom& operator = (const PlayerRandom& aux); //Assigment operator
	void nextMove(Board& aux);
	bool checkSpot(Board & aux, int i, int j);
	unsigned seedGenerator();
};

