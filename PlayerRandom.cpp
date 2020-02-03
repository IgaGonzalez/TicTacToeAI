#include "PlayerRandom.h"



PlayerRandom::PlayerRandom()
{
	character = "o";
	row = getRow();
	column = getColumn();
}

PlayerRandom::PlayerRandom(string aux)
{
	character = aux;
}

PlayerRandom::PlayerRandom(const PlayerRandom & aux)
{
	character = aux.character;
	row = aux.row;
	column = aux.column;
}


PlayerRandom::~PlayerRandom()
{
}

PlayerRandom & PlayerRandom::operator=(const PlayerRandom & aux)
{
	if (this == &aux)
		return *this;
	character = aux.character;
	row = aux.row;
	column = aux.column;
	return *this;
}

void PlayerRandom::nextMove(Board & aux)
{
	srand(seedGenerator());
	//Pick a random spot inside the grid
	row = rand() % 3;
	column = rand() % 3;
	/*
	Move bestMove;
	bestMove =  bestMove.findBestMove(aux);
	cout << "\n BestMove row" << bestMove.row <<"\n";
	cout << "\n BestMove Column" << bestMove.col <<"\n";
	aux.placeSymbol(character,bestMove.row,bestMove.col);
	aux.printBoard();
	*/
	
	assert(detRowColumn(row,column));
	if (checkSpot(aux,row,column)) {
		aux.placeSymbol(character, row, column);
		aux.printBoard();
	}
	else {
		nextMove(aux);
	}
	
}

bool PlayerRandom::checkSpot(Board & aux,int i, int j)
{
	if (aux.checkSymbol(i, j) == " ") {
		return true;
	}
	else {
		return false;
	}
}

unsigned PlayerRandom::seedGenerator()
{
	unsigned i = rand();
	return i;
}

