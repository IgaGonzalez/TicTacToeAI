#include"AI.h"
using namespace std;


bool Move::isMovesLeft(Board & aux)
{
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			if (aux.checkSymbol(i, j) == " ")
				return true;
	return false;
}

int Move::evaluate(Board & aux)
{
	//Check rows for X or O victory
	for (int row = 0; row < 3; row++) {
		if (aux.checkSymbol(row, 0) == aux.checkSymbol(row, 1) && aux.checkSymbol(row, 1) == aux.checkSymbol(row, 2)) {
			if (aux.checkSymbol(row, 0) == player)
				return +10;
			else if (aux.checkSymbol(row, 0) == opponent)
				return -10;
		}
	}
	//Check for columns
	for (int col = 0; col<3; col++)
	{
		if (aux.checkSymbol(0, col) == aux.checkSymbol(1, col) &&
			aux.checkSymbol(1, col) == aux.checkSymbol(2, col))
		{
			if (aux.checkSymbol(0, col) == player)
				return +10;

			else if (aux.checkSymbol(0, col) == opponent)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory. 
	if (aux.checkSymbol(0, 0) == aux.checkSymbol(1, 1) && aux.checkSymbol(1, 1) == aux.checkSymbol(2, 2))
	{
		if (aux.checkSymbol(0, 0) == player)
			return +10;
		else if (aux.checkSymbol(0, 0) == opponent)
			return -10;
	}

	if (aux.checkSymbol(0, 2) == aux.checkSymbol(1, 1) && aux.checkSymbol(1, 1) == aux.checkSymbol(2, 0))
	{
		if (aux.checkSymbol(0, 2) == player)
			return +10;
		else if (aux.checkSymbol(0, 2) == opponent)
			return -10;
	}

	// Else if none of them have won then return 0 
	return 0;
}

int Move::minimax(Board & aux, int depth, bool isMax)
{
	int score = evaluate(aux);
	if (score == 10)
		return score;
	if (score == -10)
		return score;

	if (isMovesLeft(aux) == false)
		return 0;

	if (isMax) {
		int best = -1000;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3;j++) {
				if (aux.checkSymbol(i, j) == " ") {
					aux.placeSymbol(player, i, j);

					best = max(best, minimax(aux, depth + 1, !isMax));
					aux.placeSymbol(" ", i, j);
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3;j++) {
				if (aux.checkSymbol(i, j) == " ") {
					aux.placeSymbol(opponent, i, j);

					best = min(best, minimax(aux, depth + 1, !isMax));
					aux.placeSymbol(" ", i, j);
				}
			}
		}
		return best;
	}
}

Move Move::findBestMove(Board & aux)
{

	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (aux.checkSymbol(i, j) == " ") {
				aux.placeSymbol(player, i, j);
				int moveVal = minimax(aux, 0, false);
				aux.placeSymbol(" ", i, j);

				if (moveVal > bestVal) {
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	return bestMove;

}
