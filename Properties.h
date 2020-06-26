#ifndef PROPERTIES_H
#define PROPERTIES_H

// Adjust below!
static const int NUM_RANKS = 8;
static const int NUM_FILES = 8; // no greater than 26

// List piece order of BLACK PIECES ONLY from POV of White, starting with back-most row upward.
// Pieces will wrap automatically, starting from the first file again after reaching the last file.
static const std::string PIECES = "RNBQKBNRPPPPPPPP";



//////////// DO NOT MODIFY BELOW ////////////
static const int NUM_EMPTY_SPACES = NUM_RANKS * NUM_FILES - PIECES.size() * 2;

#endif // PROPERTIES_H