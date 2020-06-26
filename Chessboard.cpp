#include <iostream>
#include <vector>

#include "Chessboard.h"
using namespace std;

static const int NUM_RANKS = 8;
static const int NUM_FILES = 8;

class BoardImpl : public Board
{
public:
	BoardImpl();

	// private:
	vector<vector<char>> rank = vector<vector<char>>(NUM_RANKS, vector<char>(NUM_FILES));
};

BoardImpl::BoardImpl()
{
	for (int i = 0; i < rank.size(); ++i)
		for (int j = 0; j < rank[i].size(); ++j)
			rank[i][j] = '.';
}

Board* Board::setUp()
{
	return new BoardImpl();
}

inline BoardImpl* GetImpl(Board* ptr) { return (BoardImpl*)ptr; }
inline const BoardImpl* GetImpl(const Board* ptr) { return (const BoardImpl*)ptr; }
//https://www.codeproject.com/Articles/42466/Hiding-Implementation-Details-in-C

void Board::update(string move)
{
	return;
}

void Board::display()
{
	BoardImpl* f = GetImpl(this);
	int i = NUM_RANKS;
	for (auto p : f->rank)
	{
		cout << i << "   ";
		for (auto q : p)
			cout << q << "   ";
		cout << '\n' << '\n';
		--i;
	}
	cout << "    a   b   c   d   e   f   g   h";
}