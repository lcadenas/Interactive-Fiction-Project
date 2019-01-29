#ifndef __STORYTOKENIZER_H
#define __STORYTOKENIZER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "passagetoken.h"
#include "passagetokenizer.h"
#include "sectiontoken.h"
using namespace std;

class StoryTokenizer
{
private:
	string line;
	istringstream story;
	vector<string> passvect;
public:
	StoryTokenizer(string input);
	bool hasNextPassage();
	PassageToken nextPassage();
};
#endif