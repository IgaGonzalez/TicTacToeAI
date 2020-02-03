#include "PlayerHuman.h"
#include "Player.h"
#include"Board.h"
#include<string>
PlayerHuman::PlayerHuman()
{
	/*
	b = Board();
	character = "";
	i = 0;
	j = 0;
	*/
	character = getCharacter();
	row = getRow();
	column = getColumn();

}

PlayerHuman::PlayerHuman(const PlayerHuman & aux)
{
	character = aux.character;
	row = aux.row;
	column = aux.column;
}

PlayerHuman::~PlayerHuman()
{
}

PlayerHuman & PlayerHuman::operator=(const PlayerHuman & aux)
{
	if (this == &aux)
		return *this;
	character = aux.character;
	row = aux.row;
	column = aux.column;
	return *this;
}

void PlayerHuman::nextMove(Board & aux)
{
	
	int row, column;
	string value = character;
	cout << "Enter desired row to input value: " << endl;
	cin >> row;
	cout << "Enter desired column to input value: " << endl;
	cin >> column;
	if (value == "x" || value == "o") {
		assert(detSymbol(value));
		assert(detRowColumn(row, column));
		if (checkSpot(aux, row, column)) {
			aux.placeSymbol(value, row, column);
			aux.printBoard();
		}
		else {
			cout << "\n Please enter another coordinate \n";
			nextMove(aux);
		}
	}
	else {
		cout << "Enter desired value (x/o) to input: " << endl;
		cin >> value;
		assert(detSymbol(value));
		assert(detRowColumn(row, column));
		if (checkSpot(aux, row, column)) {
			aux.placeSymbol(value, row, column);
			aux.printBoard();
		}
		else {
			cout << "\n Please enter another coordinate \n";
			nextMove(aux);
		}
	}
	
	
}

bool PlayerHuman::checkSpot(Board & aux, int i, int j)
{
	if (aux.checkSymbol(i, j) == " ") {
		return true;
	}
	else {
		return false;
	}
}

PlayerHuman::PlayerHuman(string aux)
{
	assert(detSymbol(aux));
	character = aux;
}
