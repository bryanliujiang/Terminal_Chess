#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

class Board
{
public:
	void update(int fromFile, int fromRank, int toFile, int toRank);
	void display();
	void flip(bool isTurn = true);
	char square(char file, char rank) const;
	static Board* setUp();
protected:
	Board() {}
};

#endif // CHESSBOARD_H_
