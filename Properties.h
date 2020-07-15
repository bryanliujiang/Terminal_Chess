#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include "Chessboard.h"
#include "Ruleset.h"

// Specify piece-set template to use.
#include "Pieceset_Classic.h"

// Specify the board dimensions.
const int NUM_RANKS	= 8; // cannot be greater than 9 (for now)
const int NUM_FILES	= 8; // cannot be greater than 26 (for now)

// Name the players. Choose who plays first.
const std::string PLAYER_WHITE = "White";
const std::string PLAYER_BLACK = "Black";

// List piece order of BLACK PIECES ONLY from POV of White, starting with back-most row upward.
// Pieces will wrap automatically, starting from the first file again after reaching the last file.
// MUST BE ALL UPPER CASE!
const std::string PIECES = "RNBQKBNRYYYYYYYY";

// Greet the players.
const std::string GREETING =
	"Welcome to Terminal Chess!\n\n" +
	PLAYER_WHITE + " will be uppercase.\n" +
	PLAYER_BLACK + " will be lowercase.\n\n"
	"Moves must be made like this: e2e4, e7e5, g1f3, etc.\n\n"
	"Enter /C to view list of valid commands.\n\n";

// Remember to implement a ruleset for the pieces! Otherwise, the classic ruleset
// can be applied. The implementation is in "Ruleset_Classic.cpp".



//////////////////////////////// DO NOT MODIFY BELOW ////////////////////////////////
static std::string current_player; // keeps track of current player
const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz"; // label the files
const int NUM_EMPTY_SPACES = NUM_RANKS * NUM_FILES - PIECES.size() * 2; // number of empty squares at start of game
const std::string EXIT_CODES = // what the program should return
	"Exit codes:\n"
	" 0 : Program exited successfully.\n"
	"-1 : Program exited with an error.\n";
const std::string COMMAND_CODES	= // commands player can make during their turn
	"Enter any of the following to execute its respective command. Case sensitive.\n"
	"/d : Request a draw.\n"
	"/f : Flip the board.\n"
	"/r : Resign.\n"
	"/t : View number of turns played so far.\n"
	"/E : View program exit codes\n";

const char NAME_KING	= 'K';
const char NAME_QUEEN	= 'Q';
const char NAME_ROOK	= 'R';
const char NAME_BISHOP	= 'B';
const char NAME_KNIGHT	= 'N';
const char NAME_PAWN	= 'Y';

// ID_NAME: piece name , piece number , White/Black
// piece name: King = 1, Queen = 2, Rook = 3, etc.
// piece number: 1 = first piece, 2 = second piece, etc.
// White/Black: 0 = White, 1 = Black.
// Example: 320 = second White rook, 671 = seventh Black pawn, etc.
const int ID_KING	= 100;
const int ID_QUEEN	= 200;
const int ID_ROOK	= 300;
const int ID_BISHOP = 400;
const int ID_KNIGHT = 500;
const int ID_PAWN	= 600;

const int COLOR_WHITE = 1;
const int COLOR_BLACK = 2;

#endif // PROPERTIES_H_