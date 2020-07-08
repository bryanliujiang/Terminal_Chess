#ifndef PIECESET_TEMPLATENAME_H_
#define PIECESET_TEMPLATENAME_H_

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

#endif // PIECESET_TEMPLATENAME_H_