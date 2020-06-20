#include <iostream>
#include <vector>

#include "Chessboard.h"
using namespace std;

static const int NUM_RANKS = 8;
static const int NUM_FILES = 8;

class BoardImpl : public Board
{
public:
	BoardImpl() {}
	vector<vector<char> > rank;
};

Board* Board::setUp()
{
	return new BoardImpl();
}

void Board::update(string move)
{
	return;
}