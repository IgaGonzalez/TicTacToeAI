#include "Player.h"
#include<iostream>
#include<string>
using namespace std;
Player::Player()
{

	character = "";
	i = 0;
	j = 0;
}

Player::Player(const Player & aux)
{
	character = aux.character;
	i = aux.i;
	j = aux.j;
}

Player::~Player()
{
}

Player & Player::operator=(const Player & aux)
{
	if (this == &aux)
		return *this;
	character = aux.character;
	i = aux.i;
	j = aux.j;
	return *this;
}

Player::Player(string aux)
{
	assert(detSymbol(aux));
	character = aux;
}

bool Player::detSymbol(string aux)
{
	if (aux.size() > 1) {
		//Error. Must be a single character
		return false;
	}
	else {
		//if (aux != "x" && aux != "o" && aux != "X" && aux != "O") {
		if(aux=="x" || aux=="X" || aux=="o" ||aux=="O"){
			//Error. Value must be a x or o.
			return true;
		}
		else {
			return false;
		}
	}
}

bool Player::detRowColumn(int i, int j)
{
	if (i > 3 || i < 0) {
	//Error
		return false;
	}
	else {
		if (j > 3 || j < 0) {
			//Error
			return false;
		}
		else {
			return true;
		}
	}
}

void Player::nextMove(Board & aux)
{
}



string Player::getCharacter()
{
	return character;
}

void Player::setCharacter(string aux)
{
	character = aux;
}

int Player::getRow()
{
	return i;
}

void Player::setRow(int aux)
{
	i = aux;
}

int Player::getColumn()
{
	return j;
}

void Player::setColumn(int aux)
{
	j = aux;
}



