#include<iostream>
#include<string>
#include "Board.h"
#include"PlayerHuman.h"
#include"PlayerRandom.h"
//#include"AI.h"
#include<iostream>
using namespace std;
void initialMenu() {
	cout << "Welcome to Tic Tac Toe \n";
	cout << "Please choose an option: \n";
	cout << "1) Human vs Human \n";
	cout << "2) Human vs Computer \n";
	cout << "3) Computer vs Computer \n";
	cout << "4) AI implementation \n";
};
int main() {
	int choice;
	initialMenu();
	cin >> choice;
	switch(choice) {
	case 1: { //Human vs Human
		PlayerHuman p1 = PlayerHuman("x");
		PlayerHuman p2 = PlayerHuman("o");
		Board b = Board();
		b.printBoard();
		while (!b.checkTie()) {
			p1.nextMove(b);
			if (b.checkWinner()) {
				cout << "\n P1 Won \n";
				exit(-1);
			}
			else {
				p2.nextMove(b);
				if (b.checkWinner()) {
					cout << "\n P2 Won \n";
					exit(-1);
				}
			}
		}
		break;
	}
	case 2: { //Human vs Computer
		PlayerHuman ph = PlayerHuman("x");
		PlayerRandom pr = PlayerRandom();
		Board b = Board();
		b.printBoard();
		while (!b.checkTie()) {
			ph.nextMove(b);
			if (b.checkWinner()) {
				cout << "Human Won" << endl;
				exit(-1);
			}
			else {
				pr.nextMove(b);
				if (b.checkWinner()) {
					cout << "Random spotter won" << endl;
					exit(-1);
				}
			}
		}
		break;}
	case 3: { //Computer vs Computer
		PlayerRandom p1 = PlayerRandom("x");
		PlayerRandom p2 = PlayerRandom("o");
		Board b = Board();
		b.placeSymbol("x",0,0);
		b.printBoard();

		while (!b.checkTie()) {
			p2.nextMove(b);
			if (b.checkWinner()) {
				cout << "P1 Won" << endl;
				exit(-1);
			}
			else {
				p1.nextMove(b);
				if (b.checkWinner()) {
					cout << "P2 won" << endl;
					exit(-1);
				}
			}
		}
		break;}
	case 4: {
		PlayerHuman ph = PlayerHuman("o");
		PlayerRandom pr = PlayerRandom("x");
		Board b = Board();
		
		b.placeSymbol("x",0,0);
		b.printBoard();
		while (!b.checkTie()) {
			ph.nextMove(b);
			if (b.checkWinner()) {
				cout << "Human Won" << endl;
				exit(-1);
			}
			else {
				pr.nextMove(b);
				if (b.checkWinner()) {
					cout << "Random spotter won" << endl;
					exit(-1);
				}
			}
		}
		break;}
	default: 
		cout << "\n Wrong choice \n";
		break;
	}
	

}
