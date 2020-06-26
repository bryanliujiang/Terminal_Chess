#include <iostream>
#include <vector>
#include<algorithm>

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
	cout << "Welcome to Chess!\n\n"
		<< "White = Uppercase\n"
		<< "Black = Lowercase\n\n"
		<< "Moves must be made like this: e2e4, e7e5, g1f3, etc.\n\n"
		<< endl;
	
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

	string pieces = PIECES;
	transform(pieces.begin(), pieces.end(), pieces.begin(), ::tolower);
    string squares = pieces;
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

void Board::update(int fromFile, int fromRank, int toFile, int toRank)
{
	BoardImpl* priv = GetImpl(this);
	char from = priv->rank[fromRank][fromFile];
	priv->rank[fromRank][fromFile] = '.';
	priv->rank[toRank][toFile] = from;
}

void Board::display()
{
	BoardImpl* priv = GetImpl(this);
	int i = NUM_RANKS;
	for (auto p : priv->rank)
	{
		cout << i << "     ";
		for (auto q : p)
			cout << q << "   ";
		cout << '\n' << '\n';
		--i;
	}
	cout << '\n' << "   ";
	for (i = 0; i < NUM_FILES; ++i)
		cout << "   " << alphabet[i];
	cout << endl;
}

void Board::flip()
{
	BoardImpl* priv = GetImpl(this);
	string squares;
	for (auto p : priv->rank)
		for (auto q : p)
			squares += q;
	reverse(squares.begin(), squares.end());
	int counter = 0;
	for (int i = 0; i < priv->rank.size(); ++i)
		for (int j = 0; j < priv->rank[i].size(); ++j)
		{
			priv->rank[i][j] = squares[counter];
			++counter;
		}
}