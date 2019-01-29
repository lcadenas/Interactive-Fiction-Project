#ifndef __BLOCKTOKENIZER_H
#define __BLOCKTOKENIZER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "sectiontoken.h"
using namespace std;

class BlockTokenizer
{
private:
	string blocksec, section;
	istringstream input;
	vector<string> blockVect;
public:
	BlockTokenizer(string str);
	SectionToken nextBlockSection();
	bool hasNextBlockSection();
};
#endif
