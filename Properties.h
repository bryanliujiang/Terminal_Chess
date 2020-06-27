#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <string>

// Specify the board dimensions.
static const int NUM_RANKS = 8;
static const int NUM_FILES = 8; // cannot be greater than 26

// Name the players.
static const std::string PLAYER_WHITE = "White";
static const std::string PLAYER_BLACK = "Black";

// List piece order of BLACK PIECES ONLY from POV of White, starting with back-most row upward.
// Pieces will wrap automatically, starting from the first file again after reaching the last file.
// MUST BE ALL UPPER CASE!
static const std::string PIECES = "RNBQKBNRYYYYYYYY";

// Greet the players.
static const std::string GREETING =
"Welcome to Chess!\n\n" +
PLAYER_WHITE + " will be uppercase.\n" +
PLAYER_BLACK + " will be lowercase.\n\n"
"Moves must be made like this: e2e4, e7e5, g1f3, etc.\n\n"
"Enter /C to view list of valid commands.\n\n";

//////////////////////////////// DO NOT MODIFY BELOW ////////////////////////////////
static std::string CURRENT_PLAYER = PLAYER_WHITE; // keep track of current player; White moves first.
static const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz"; // label the files
static const int NUM_EMPTY_SPACES = NUM_RANKS * NUM_FILES - PIECES.size() * 2;
static const std::string EXIT_CODES =
"Exit codes:\n"
" 0 : Program exited successfully.\n"
"-1 : Program exited with an error.\n";
static const std::string COMMAND_CODES =
"Enter any of the following to execute its respective command. Case sensitive.\n"
"/f : Flip the board.\n"
"/r : Resign.\n"
"/E : View program exit codes\n";

#endif // PROPERTIES_H