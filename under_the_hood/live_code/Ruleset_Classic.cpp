#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

#include "Properties.h"
using namespace std;

void unnamedFunction(string self, string nonself);

bool isValidTurnBasedOnRuleset(string move, Board* board)
{
	char ff = move[0]; // from file
	char fr = move[1]; // from rank
	char tf = move[2]; // to file
	char tr = move[3]; // to rank

	int fd = abs(tr - fr); // file difference (distance difference along file)
	int rd = abs(tf - ff); // rank difference (distance difference along rank)

	bool stillValid = true;
	string pieceName;

	string whitePieces = PIECES; // "RNBQKBNRYYYYYYYY"
	sort(whitePieces.begin(), whitePieces.end());
	transform(whitePieces.begin(), whitePieces.end(), whitePieces.begin(), ::tolower);
	string blackPieces = whitePieces; // "rnbqkbnryyyyyyyy"
	auto itr = unique(whitePieces.begin(), whitePieces.end()); // "BKNQRY"
	itr = unique(blackPieces.begin(), blackPieces.end()); // "bknqry"

	vector<pair<char, char>> validMoves;
	char cf = ff; // current file
	char cr = fr; // current rank
	
	if (fd == 0 && rd == 0) // ff == tf && fr == tr
	{
		cout << "Piece did not move anywhere. Try again." << endl;
		return false; // cannot move piece to own square
	}

	switch (onSquare(ff, fr, board))
	{
	case 'K':
		pieceName = "White King";

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
			
			stillValid = false;
		}
		break;
	case 'k':
		pieceName = "Black King";

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
			
			stillValid = false;
		}
		break;

	case 'Q':
		pieceName = "White Queen";

		if (fd > 0 && rd > 0)
			if (fd != rd)
			{
				
				stillValid = false;
			}
		break;
	case 'q':
		pieceName = "Black Queen";

		if (fd > 0 && rd > 0)
			if (fd != rd)
			{
				
				stillValid = false;
			}
		break;

	case 'R':
		pieceName = "White Rook";

		if (fd > 0 && rd > 0)
		{
			
			stillValid = false;
		}
		break;
	case 'r':
		pieceName = "Black Rook";

		if (fd > 0 && rd > 0)
		{
			
			stillValid = false;
		}
		break;

	case 'B':
		pieceName = "White Bishop";

		if (fd != rd)
		{
			
			stillValid = false;
		}
		break;
	case 'b':
		pieceName = "Black Bishop";

		if (fd != rd)
		{
			
			stillValid = false;
		}
		break;

	case 'N':
		pieceName = "White Knight";

		if ((fd == 2 && rd == 1) || (fd == 1 && rd == 2))
			;
		else
		{
			
			stillValid = false;
		}
		break;
	case 'n':
		pieceName = "Black Knight";

		if ((fd == 2 && rd == 1) || (fd == 1 && rd == 2))
			;
		else
		{
			
			stillValid = false;
		}
		break;

	case 'Y':
		pieceName = "White Pawn";

		if (rd > 1 || fd > 2 || fd == 0 || tr - fr < 0)
		{
			
			stillValid = false;
		}
		break;
	case 'y':
		pieceName = "Black Pawn";

		if (rd > 1 || fd > 2 || fd == 0 || tr - fr > 0)
		{
			
			stillValid = false;
		}
		break;

	case '.':
		cout << "An unknown error has occured. This program must terminate." << endl;
		exit(-1);
		break;
	default:
		cout << "Inconsistency in piece set and ruleset. This program must terminate." << endl;
		exit(-1);
	}

	if (stillValid)
		return true;
	else
	{
		cout << pieceName << " move is illegal. Try again." << endl;
		return false;
	}
}