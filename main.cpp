#include "Chessboard.h"
#include "Match.h"
#include "Properties.h"
#include <iostream>

#include "Match.h"
using namespace std;

// return 0 : success
// return -1 : error
int main()
{
	Match* round = Match::create();
	return round->start();
}