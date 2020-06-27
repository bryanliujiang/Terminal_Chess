#include <algorithm>
#include <iostream>

#include "Chessboard_OLD.h"
using namespace std;

Board::Board()
	: numTurns(0)
{
	cout << GREETING << endl;

	vector<string> rows;
	string row;
	int counter = 0;
	for (size_t i = 0; i < PIECES.size(); ++i)
	{
		row += PIECES[i];
		++counter;
		if (counter == NUM_FILES ||
			i == PIECES.size() - 1) // push rest of row during final iteration
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

	for (size_t i = 0; i < rank.size(); ++i)
		for (size_t j = 0; j < rank[i].size(); ++j)
		{
			rank[i][j] = squares[counter];
			++counter;
		}
}

void Board::update(int fromFile, int fromRank, int toFile, int toRank)
{
	char from = rank[fromRank][fromFile];
	rank[fromRank][fromFile] = '.';
	rank[toRank][toFile] = from;
}

void Board::display()
{
	if (numTurns % 2 == 0) // even number of turns means it is White to move
	{
		int i = NUM_RANKS;
		for (auto p : rank)
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
		for (auto p : rank)
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
	string squares;
	for (auto p : rank)
		for (auto q : p)
			squares += q;
	reverse(squares.begin(), squares.end());
	int counter = 0;
	for (size_t i = 0; i < rank.size(); ++i)
		for (size_t j = 0; j < rank[i].size(); ++j)
		{
			rank[i][j] = squares[counter];
			++counter;
		}
	if (isTurn)
		++numTurns;
}