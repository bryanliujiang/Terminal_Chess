#ifndef PIECESET_CLASSIC_H_
#define PIECESET_CLASSIC_H_

class Board;

class Piece
{
public:
private:
};

class King : public Piece
{
public:
	King();
private:
	bool isInCheck;
	bool hasMoved;
};

#endif // PIECESET_CLASSIC_H_