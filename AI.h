#pragma once
#include"Board.h"
#include <algorithm>
using namespace std;
struct Move {
	int row, col;
	string player = "x", opponent = "o";
	bool isMovesLeft(Board& aux);
	int evaluate(Board& aux);
	int minimax(Board& aux, int depth, bool isMax);
	Move findBestMove(Board& aux);
};
