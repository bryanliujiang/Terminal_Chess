#include <iostream>

#include "Properties.h"
using namespace std;

bool isValidTurnBasedOnRuleset(int fromFile, int fromRank, int toFile, int toRank)
{
	if (fromFile == fromRank && fromRank == toRank)
	{
		cout << "Piece did not move anywhere. Try again." << endl;
		return false; // cannot move piece to own square
	}

	

	return true;
}