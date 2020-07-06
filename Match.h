#ifndef MATCH_H_
#define MATCH_H_

class Match
{
public:
	int result();
	static Match* create();
protected:
	Match() {}
};

#endif // MATCH_H_
