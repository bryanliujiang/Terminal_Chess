#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class Board
{
public:
	void update(int fromFile, int fromRank, int toFile, int toRank);
	void display();
	void flip(bool isTurn = true);
	static Board* setUp();
protected:
	Board() {}
};

#endif // CHESSBOARD_H
