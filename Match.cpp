#include <iostream>

#include "Chessboard.h"
#include "Match.h"
#include "Properties.h"
using namespace std;

class MatchImpl : public Match
{
public:
	MatchImpl();

	// private:
	bool isWhite;
};

MatchImpl::MatchImpl()
	: isWhite(true)
{
}

Match* Match::create()
{
	return new MatchImpl();
}

inline MatchImpl* GetImpl(Match* ptr) { return (MatchImpl*)ptr; }
inline const MatchImpl* GetImpl(const Match* ptr) { return (const MatchImpl*)ptr; }
//https://www.codeproject.com/Articles/42466/Hiding-Implementation-Details-in-C

int Match::start()
{
	if (NUM_FILES > 26)
	{
		cout << "Error: Too many files!" << endl;
		return -1;
	}
	if (NUM_EMPTY_SPACES < 0)
	{
		cout << "Error: Too many pieces!" << endl;
		return -1;
	}
	
	MatchImpl* priv = GetImpl(this);
	Board* game = Board::setUp();
	string player;

	while (true)
	{
		string move;
		int ff, fr, tf, tr; // from file, from rank, to file, to rank
		if (priv->isWhite == true)
			player = "White";
		else
			player = "Black";

		game->display();
		
		do
		{
			cout << '\n' << player << " to move: ";
			cin >> move;
		}
		while (!isValidMoveSyntax(move) || !isValidTurn(move));

		cout << '\n' << player << " moved from " << move[0] << move[1] << " to " << move[2] << move[3] << ".\n" << endl;

		if (priv->isWhite)
		{
			ff = move[0] - 97;
			fr = NUM_RANKS - (move[1] - '0');
			tf = move[2] - 97;
			tr = NUM_RANKS - (move[3] - '0');
			priv->isWhite = false;
		}
		else
		{
			ff = NUM_FILES - (move[0] - 97) - 1;
			fr = move[1] - '0' - 1;
			tf = NUM_FILES - (move[2] - 97) - 1;
			tr = move[3] - '0' - 1;
			priv->isWhite = true;
		}

		game->update(ff, fr, tf, tr);
		game->flip();
	}

	return 0;
}

bool Match::isValidMoveSyntax(string move)
{
	if (move.size() != 4)
	{
		cout << "Invalid syntax. Try again." << endl;
		return false;
	}

	int ff, fr, tf, tr; // from file, from rank, to file, to rank

	ff = move[0] - 97;
	if (ff >= NUM_FILES || ff < 0)
	{
		cout << "Invalid square(s). Try again." << endl;
		return false; // file does not exist
	}

	fr = move[1] - '0';
	if (fr > NUM_RANKS || fr == 0)
	{
		cout << "Invalid square(s). Try again." << endl;
		return false; // rank does not exist
	}

	tf = move[2] - 97;
	if (tf >= NUM_FILES || tf < 0)
	{
		cout << "Invalid square(s). Try again." << endl;
		return false; // file does not exist
	}

	tr = move[3] - '0';
	if (tr > NUM_RANKS || tr == 0)
	{
		cout << "Invalid square(s). Try again." << endl;
		return false; // rank does not exist
	}

	return true;
}

bool Match::isValidTurn(string move)
{
	int ff, fr, tf, tr; // from file, from rank, to file, to rank
	ff = move[0] - 97;
	fr = move[1] - '0';
	tf = move[2] - 97;
	tr = move[3] - '0';

	if (ff == tf && fr == tr)
	{
		cout << "Piece did not move anywhere. Try again." << endl;
		return false; // cannot move piece to own square
	}

	return true;
}