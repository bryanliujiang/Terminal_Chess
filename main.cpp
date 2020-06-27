#include "Chessboard.h"
#include "Match.h"
#include "Properties.h"
class Match;

int main()
{
	Match* round = Match::create();
	return round->start();
}