#include <iostream>
#include <vector>

#include "Properties.h"
#include "Chessboard.h"
using namespace std;

static const string alphabet = "abcdefghijklmnopqrstuvwxyz"; // label the files

class BoardImpl : public Board
{
public:
	BoardImpl();

	// private:
	vector<vector<char>> rank = vector<vector<char>>(NUM_RANKS, vector<char>(NUM_FILES));
};

BoardImpl::BoardImpl()
{
	vector<string> rows;
	string row;
	int counter = 0;
	for (int i = 0; i < PIECES.size(); ++i)
	{
		row += PIECES[i];
		++counter;
		if (counter == NUM_FILES)
		{
			rows.push_back(row);
			row.clear();
			counter = 0;
		}
	}

    string squares = PIECES;
	for (int i = 0; i < NUM_EMPTY_SPACES; ++i)
		squares += '.';
	for (auto p = rows.rbegin(); p != rows.rend(); ++p)
		squares += *p;

	for (int i = 0; i < rank.size(); ++i)
		for (int j = 0; j < rank[i].size(); ++j)
		{
			rank[i][j] = squares[counter];
			++counter;
		}
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
		cout << i;
		for (auto q : p)
			cout << "   " << q;
		cout << '\n' << '\n';
		--i;
	}
	cout << ' ';
	for (i = 0; i < NUM_FILES; ++i)
		cout << "   " << alphabet[i];
}