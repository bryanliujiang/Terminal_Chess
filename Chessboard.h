#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<string>

class Board
{
public:
	void update(std::string move);
	static Board* setUp();
protected:
	Board() {}
};

#endif // CHESSBOARD_H
