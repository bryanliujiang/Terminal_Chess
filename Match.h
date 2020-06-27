#ifndef MATCH_H
#define MATCH_H

class Match
{
public:
	int start();
	static Match* create();
protected:
	Match() {}
};

#endif // MATCH_H
