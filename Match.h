#ifndef MATCH_H
#define MATCH_H

#include <string>

class Match
{
public:
	int start();
	bool isValidRules();
	bool isValidMoveSyntax(std::string move);
	bool isValidTurn(std::string move);
	bool isCommand(std::string move, Board* board);
	static Match* create();
protected:
	Match() {}
};

#endif // MATCH_H
