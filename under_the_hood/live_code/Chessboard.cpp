#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include "Properties.h"
using namespace std;

class BoardImpl : public Board
{
public:
	BoardImpl();
	vector<vector<char>> rank = vector<vector<char>>(NUM_RANKS, vector<char>(NUM_FILES));
	vector<Piece*> pieceset;
	int numTurns;
};

BoardImpl::BoardImpl()
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

	int nK = 1, nQ = 1, nR = 1, nB = 1, nN = 1, nP = 1;
	int nk = 1, nq = 1, nr = 1, nb = 1, nn = 1, np = 1;

	for (size_t i = 0; i < rank.size(); ++i)
		for (size_t j = 0; j < rank[i].size(); ++j)
		{
			bool isWhite = true;
			char cur = squares[counter];
			
			if (islower(cur))
			{
				isWhite = false;
				cur = toupper(cur);
			}

			switch (cur)
			{
			case NAME_KING:
				if (isWhite)
				{
					pieceset.push_back(new King(this, NAME_KING, ID_KING, COLOR_WHITE, nK, i, j));
					++nK;
				}
				else
				{
					pieceset.push_back(new King(this, NAME_KING, ID_KING, COLOR_BLACK, nk, i, j));
					++nk;
				}
				break;
			case NAME_QUEEN:
				if (isWhite)
				{
					pieceset.push_back(new Queen(this, NAME_QUEEN, ID_QUEEN, COLOR_WHITE, nQ, i, j));
					++nQ;
				}
				else
				{
					pieceset.push_back(new Queen(this, NAME_QUEEN, ID_QUEEN, COLOR_BLACK, nq, i, j));
					++nq;
				}
				break;
			case NAME_ROOK:
				if (isWhite)
				{
					pieceset.push_back(new Rook(this, NAME_ROOK, ID_ROOK, COLOR_WHITE, nR, i, j));
					++nR;
				}
				else
				{
					pieceset.push_back(new Rook(this, NAME_ROOK, ID_ROOK, COLOR_BLACK, nr, i, j));
					++nr;
				}
				break;
			case NAME_BISHOP:
				if (isWhite)
				{
					pieceset.push_back(new Bishop(this, NAME_BISHOP, ID_BISHOP, COLOR_WHITE, nB, i, j));
					++nB;
				}
				else
				{
					pieceset.push_back(new Bishop(this, NAME_BISHOP, ID_BISHOP, COLOR_BLACK, nb, i, j));
					++nb;
				}
				break;
			case NAME_KNIGHT:
				if (isWhite)
				{
					pieceset.push_back(new Knight(this, NAME_KNIGHT, ID_KNIGHT, COLOR_WHITE, nN, i, j));
					++nN;
				}
				else
				{
					pieceset.push_back(new Knight(this, NAME_KNIGHT, ID_KNIGHT, COLOR_BLACK, nn, i, j));
					++nn;
				}
				break;
			case NAME_PAWN:
				if (isWhite)
				{
					pieceset.push_back(new Pawn(this, NAME_PAWN, ID_PAWN, COLOR_WHITE, nP, i, j));
					++nP;
				}
				else
				{
					pieceset.push_back(new Pawn(this, NAME_PAWN, ID_PAWN, COLOR_BLACK, np, i, j));
					++np;
				}
				break;
			}
			
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
	for (size_t i = 0; i < priv->rank.size(); ++i)
		for (size_t j = 0; j < priv->rank[i].size(); ++j)
		{
			priv->rank[i][j] = squares[counter];
			++counter;
		}
	if (isTurn)
		++priv->numTurns;
}

int Board::numTurns() const
{
	const BoardImpl* priv = GetImpl(this);
	return priv->numTurns;
}

char onSquare(char file, char rank, Board* board)
{
	BoardImpl* priv = GetImpl(board);
	if (priv->numTurns % 2 == 0) // even number of turns means it is White to move
		return priv->rank[NUM_RANKS - (rank - '0')][file - 97];
	else
		return priv->rank[rank - '0' - 1][NUM_FILES - (file - 97) - 1];
}