#include <iostream>
#include <vector>
#include <algorithm>

#include "Chessboard.h"
#include "Properties.h"
using namespace std;

class BoardImpl : public Board
{
public:
	BoardImpl();

	// private:
	vector<vector<char>> rank = vector<vector<char>>(NUM_RANKS, vector<char>(NUM_FILES));
	int numTurns;
};

BoardImpl::BoardImpl()
	: numTurns(0)
{
	cout << GREETING << endl;
	
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

	if (priv->numTurns % 2 == 0) // even number of turns means it is White to move
	{
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
			cout << "   " << ALPHABET[i];
		cout << endl;
	}
	else
	{
		int i = 1; // 
		for (auto p : priv->rank)
		{
			cout << i << "     ";
			for (auto q : p)
				cout << q << "   ";
			cout << '\n' << '\n';
			++i; //
		}
		cout << '\n' << "   ";
		for (i = NUM_FILES - 1; i >= 0; --i) //
			cout << "   " << ALPHABET[i];
		cout << endl;
	}
}

void Board::flip(bool isTurn)
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
	if (isTurn)
		++priv->numTurns;
}

Board* Board::setUp()
{
	return new BoardImpl();
}