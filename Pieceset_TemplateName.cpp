#include <iostream>

#include "Properties.h"
using namespace std;

class King : public Piece
{
public:
	King();
private:
	bool isInCheck;
	bool hasMoved;
};

King::King()
	: isInCheck(false), hasMoved(false)
{
}

///////////////////////////////////////////////
// ENTER CUSTOM PIECESET IMPLEMENTATION HERE //
///////////////////////////////////////////////