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

	int fd = abs(tf - ff); // file distance
	int rd = abs(tr - fr); // rank distance
	
	if (ff == tf && fr == tr)
	{
		cout << "Piece did not move anywhere. Try again." << endl;
		return false; // cannot move piece to own square
	}

	switch (onSquare(ff, fr, board))
	{
	case 'K':
		

		
		break;
	case 'k':
		break;

	case 'Q':
		break;
	case 'q':
		break;

	case 'R':
		break;
	case 'r':
		break;

	case 'B':
		break;
	case 'b':
		break;

	case 'N':
		break;
	case 'n':
		break;

	case 'Y':
		break;
	case 'y':
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