#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<string>

class Board
{
public:
	void update(int fromFile, int fromRank, int toFile, int toRank);
	static Board* setUp();
	void display();
	void flip();
protected:
	Board() {}
};

#endif // CHESSBOARD_H
