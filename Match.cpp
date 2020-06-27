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

inline MatchImpl* GetImpl(Match* ptr) { return (MatchImpl*)ptr; }
inline const MatchImpl* GetImpl(const Match* ptr) { return (const MatchImpl*)ptr; }
//https://www.codeproject.com/Articles/42466/Hiding-Implementation-Details-in-C

int Match::start()
{
	if(!isValidRules())
		return -1;
	
	MatchImpl* priv = GetImpl(this);
	Board* game = Board::setUp();

	while (true)
	{
		string move;
		int ff, fr, tf, tr; // from file, from rank, to file, to rank
		if (priv->isWhite == true)
			CURRENT_PLAYER = PLAYER_WHITE;
		else
			CURRENT_PLAYER = PLAYER_BLACK;

		game->display();
		
		do
		{
			cout << '\n' << CURRENT_PLAYER << " to move: ";
			cin >> move;
		}
		while (isCommand(move, game) || !isValidMoveSyntax(move) || !isValidTurn(move));

		cout << '\n' << CURRENT_PLAYER << " moved from " << move[0] << move[1] << " to " << move[2] << move[3] << ".\n" << endl;

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

bool Match::isValidRules()
{
	if (PIECES.size() == 0)
	{
		cout << "Error: No pieces." << endl;
		return false;
	}
	if (NUM_RANKS > 9)
	{
		cout << "Error: Too many ranks." << endl;
		return false;
	}
	if (NUM_FILES > 26)
	{
		cout << "Error: Too many files." << endl;
		return false;
	}
	if (NUM_EMPTY_SPACES < 0)
	{
		cout << "Error: Not enough squares." << endl;
		return false;
	}
	if (NUM_RANKS < 0 || NUM_FILES < 0)
	{
		cout << "Error: Cannot have negative number of ranks and/or files." << endl;
		return false;
	}

	return true;
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

bool Match::isCommand(std::string move, Board* board)
{
	if (move.size() != 2 || move[0] != '/')
		return false; // all commands are '/' followed by a single character

	char command = move[1];
	cout << '\n';
	
	switch (command)
	{
	case 'f': // Flips board
		board->flip(false); // do not count flip toward number of turns
		board->display();
		cout << "\nPress ENTER to revert board orientiation." << endl;
		cin.ignore();
		cin.get();
		board->flip(false); // do not count flip toward number of turns
		board->display();
		break;
	case 'r':
		cout << CURRENT_PLAYER + " resigns." << endl;
		exit(0);
	case 'C':
		cout << COMMAND_CODES;
		break;
	case 'E':
		cout << EXIT_CODES;
		break;
	default:
		cout << "Not a valid command. Try again. Commands are case sensitive.\n"
			"Enter /C to view list of commands." << endl;
	}
	
	return true;
}

Match* Match::create()
{
	return new MatchImpl();
}