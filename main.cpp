#include "Chessboard.h"
#include "Properties.h"
#include <iostream>

using namespace std;

int main()
{
	Board* first = Board::setUp();
	
	while (true)
	{
		string move;
		int ff, fr, tf, tr;

		first->display();
		cout << '\n' << "White" << "'s move: ";
		cin >> move;
		// if (isValidMove(move))
		ff = move[0] - 97;
		fr = NUM_RANKS - (move[1] - '0');
		tf = move[2] - 97;
		tr = NUM_RANKS - (move[3] - '0');

		first->update(ff, fr, tf, tr);

		cout << '\n' << "White just moved from " << move[0] << move[1] << " to " << move[2] << move[3] << ".\n" << endl;
	}



	
	return 0;
}