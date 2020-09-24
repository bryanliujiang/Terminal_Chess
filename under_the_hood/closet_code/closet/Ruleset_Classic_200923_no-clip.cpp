#include <iostream>
#include <cstdlib>

#include "Properties.h"
using namespace std;

bool isValidTurnBasedOnRuleset(string move, Board* board)
{
	char ff = move[0]; // from file
	char fr = move[1]; // from rank
	char tf = move[2]; // to file
	char tr = move[3]; // to rank

	int fd = abs(tr - fr); // file difference (distance difference along file)
	int rd = abs(tf - ff); // rank difference (distance difference along rank)

	if (fd == 0 && rd == 0) // ff == tf && fr == tr
	{
		cout << "Piece did not move anywhere. Try again." << endl;
		return false; // cannot move piece to own square
	}

	switch (onSquare(ff, fr, board))
	{
	case 'K':
		if ((fd == 0 && rd == 1) || (fd == 1 && rd == 0) || (fd == 1 && rd == 1))
			;
		else if ((ff == 'e' && fr == '1') && (onSquare('h', '1', board) == 'R'
			|| onSquare('a', '1', board) == 'R') && (rd == 2 && fd == 0)) // King castling
		{
			if (tf - ff > 0) // Castling kingside
				board->update('h' - 97, NUM_RANKS - ('1' - '0'), 'f' - 97, NUM_RANKS - ('1' - '0'));
			if (tf - ff < 0) // Castling queenside
				board->update('a' - 97, NUM_RANKS - ('1' - '0'), 'd' - 97, NUM_RANKS - ('1' - '0'));
		}
		else
		{
			cout << "Illegal King move from White. Try again." << endl;
			return false;
		}
		break;
	case 'k':
		if ((fd == 0 && rd == 1) || (fd == 1 && rd == 0) || (fd == 1 && rd == 1))
			;
		else if ((ff == 'e' && fr == '8') && (onSquare('h', '8', board) == 'r'
			|| onSquare('a', '8', board) == 'r') && (rd == 2 && fd == 0)) // King castling
		{
			if (tf - ff > 0) // Castling kingside
				board->update(NUM_FILES - ('h' - 97) - 1, '8' - '0' - 1, NUM_FILES - ('f' - 97) - 1, '8' - '0' - 1);
			if (tf - ff < 0) // Castling queenside
				board->update(NUM_FILES - ('a' - 97) - 1, '8' - '0' - 1, NUM_FILES - ('d' - 97) - 1, '8' - '0' - 1);
		}
		else
		{
			cout << "Illegal King move from White. Try again." << endl;
			return false;
		}
		break;

	case 'Q':
		if (fd > 0 && rd > 0)
			if (fd != rd)
			{
				cout << "Illegal Queen move from White. Try again." << endl;
				return false;
			}
		break;
	case 'q':
		if (fd > 0 && rd > 0)
			if (fd != rd)
			{
				cout << "Illegal Queen move from Black. Try again." << endl;
				return false;
			}
		break;

	case 'R':
		if (fd > 0 && rd > 0)
		{
			cout << "Illegal Rook move from White. Try again." << endl;
			return false;
		}
		break;
	case 'r':
		if (fd > 0 && rd > 0)
		{
			cout << "Illegal Rook move from Black. Try again." << endl;
			return false;
		}
		break;

	case 'B':
		if (fd != rd)
		{
			cout << "Illegal Bishop move from White. Try again." << endl;
			return false;
		}
		break;
	case 'b':
		if (fd != rd)
		{
			cout << "Illegal Bishop move from Black. Try again." << endl;
			return false;
		}
		break;

	case 'N':
		if ((fd == 2 && rd == 1) || (fd == 1 && rd == 2))
			;
		else
		{
			cout << "Illegal Knight move from White. Try again." << endl;
			return false;
		}
		break;
	case 'n':
		if ((fd == 2 && rd == 1) || (fd == 1 && rd == 2))
			;
		else
		{
			cout << "Illegal Knight move from Black. Try again." << endl;
			return false;
		}
		break;

	case 'Y':
		if (rd > 1 || fd > 2 || fd == 0 || tr - fr < 0)
		{
			cout << "Illegal Pawn move from White. Try again." << endl;
			return false;
		}
		break;
	case 'y':
		if (rd > 1 || fd > 2 || fd == 0 || tr - fr > 0)
		{
			cout << "Illegal Pawn move from Black. Try again." << endl;
			return false;
		}
		break;

	case '.':
		cout << "An unknown error has occured. This program must terminate." << endl;
		exit(-1);
		break;
	default:
		cout << "Inconsistency in piece set and ruleset. This program must terminate." << endl;
	}

	return true;
}