#include <iostream>

#include "Properties.h"
using namespace std;

Piece::Piece(Board* b, char name, int piece, int color, int instance, int currentFile, int currentRank)
	: m_currentBoard(b), m_displayName(name), m_currentFile(currentFile), m_currentRank(currentRank)
{
	if (instance > 9)
	{
		cout << "Too many of one piece. Program must terminate." << endl;
		exit(-1);
	}
	else if (instance < 1)
	{
		cout << "Piece instance must be a whole number between 1 and 9 inclusive. Program must terminate." << endl;
		exit(-1);
	}
	else // instance is integer between 1 and 9 inclusive
	{
		instance *= 10;
		m_ID = piece + instance + color;
	}
}

Piece::~Piece()
{
}

King::King(Board* b, char name, int piece, int color, int instance, int currentFile, int currentRank)
	: Piece(b, name, piece, color, instance, currentFile, currentRank), m_inCheck(false), m_hasMoved(false)
{
}

Queen::Queen(Board* b, char name, int piece, int color, int instance, int currentFile, int currentRank)
	: Piece(b, name, piece, color, instance, currentFile, currentRank)
{
}

Rook::Rook(Board* b, char name, int piece, int color, int instance, int currentFile, int currentRank)
	: Piece(b, name, piece, color, instance, currentFile, currentRank)
{
}

Bishop::Bishop(Board* b, char name, int piece, int color, int instance, int currentFile, int currentRank)
	: Piece(b, name, piece, color, instance, currentFile, currentRank)
{
}

Knight::Knight(Board* b, char name, int piece, int color, int instance, int currentFile, int currentRank)
	: Piece(b, name, piece, color, instance, currentFile, currentRank)
{
}

Pawn::Pawn(Board* b, char name, int piece, int color, int instance, int currentFile, int currentRank)
	: Piece(b, name, piece, color, instance, currentFile, currentRank)
{
}