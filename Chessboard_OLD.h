#ifndef CHESSBOARD_OLD_H
#define CHESSBOARD_OLD_H

#include <vector>

#include "Properties.h"

class Board
{
public:
	Board();
	void update(int fromFile, int fromRank, int toFile, int toRank);
	void display();
	void flip(bool isTurn = true);
private:
	int numTurns;
	std::vector<std::vector<char>> rank = std::vector<std::vector<char>>(NUM_RANKS, std::vector<char>(NUM_FILES));
};

#endif // CHESSBOARD_OLD_H