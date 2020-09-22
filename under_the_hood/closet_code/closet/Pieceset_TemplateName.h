#ifndef PIECESET_TEMPLATENAME_H_
#define PIECESET_TEMPLATENAME_H_

class Board;

class Piece
{
public:
	Piece(Board* b, char name, int piece, int color, int instance, int currentRank, int currentFile);
	virtual ~Piece();
	//virtual void checksKing() = 0;
	int onRank() const;
	int onFile() const;
	int getID() const;
private:
	Board* m_currentBoard;
	char m_displayName;
	int m_currentRank;
	int m_currentFile;
	int m_ID;
};

inline int Piece::onRank() const
{
	return m_currentRank;
}

inline int Piece::onFile() const
{
	return m_currentFile;
}

inline int Piece::getID() const
{
	return m_ID;
}

class King : public Piece
{
public:
	King(Board* b, char name, int piece, int color, int instance, int currentRank, int currentFile);
	bool isInCheck();
	bool hasMoved();
private:
	bool m_inCheck;
	bool m_hasMoved;
};

inline bool King::isInCheck()
{
	return m_inCheck;
}

inline bool King::hasMoved()
{
	return m_hasMoved;
}

/////////////////////////////////////////////
// ENTER CUSTOM PIECESET DECLARATIONS HERE //
/////////////////////////////////////////////

#endif // PIECESET_TEMPLATENAME_H_