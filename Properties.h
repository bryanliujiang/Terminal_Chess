#ifndef PROPERTIES_H_
#define PROPERTIES_H_

// Specify the board dimensions.
const int NUM_RANKS				 = 8; // cannot be greater than 9 (for now)
const int NUM_FILES				 = 8; // cannot be greater than 26 (for now)

// Name the players. Choose who plays first.
const std::string PLAYER_WHITE	 = "White";
const std::string PLAYER_BLACK	 = "Black";

// List piece order of BLACK PIECES ONLY from POV of White, starting with back-most row upward.
// Pieces will wrap automatically, starting from the first file again after reaching the last file.
// MUST BE ALL UPPER CASE!
const std::string PIECES		 = "RNBQKBNRYYYYYYYY";

// Greet the players.
const std::string GREETING		 =
	"Welcome to Terminal Chess!\n\n" +
	PLAYER_WHITE + " will be uppercase.\n" +
	PLAYER_BLACK + " will be lowercase.\n\n"
	"Moves must be made like this: e2e4, e7e5, g1f3, etc.\n\n"
	"Enter /C to view list of valid commands.\n\n";



//////////////////////////////// DO NOT MODIFY BELOW ////////////////////////////////
static std::string current_player; // keeps track of current player
const std::string ALPHABET			= "abcdefghijklmnopqrstuvwxyz"; // label the files
const int NUM_EMPTY_SPACES			= NUM_RANKS * NUM_FILES - PIECES.size() * 2; // number of empty squares at start of game
const std::string EXIT_CODES		= // what the program should return
	"Exit codes:\n"
	" 0 : Program exited successfully.\n"
	"-1 : Program exited with an error.\n";
const std::string COMMAND_CODES		= // commands player can make during their turn
	"Enter any of the following to execute its respective command. Case sensitive.\n"
	"/f : Flip the board.\n"
	"/r : Resign.\n"
	"/E : View program exit codes\n";

#endif // PROPERTIES_H_