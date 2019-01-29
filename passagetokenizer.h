#ifndef __PASSAGETOKENIZER_H
#define __PASSAGETOKENIZER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "sectiontoken.h"
using namespace std;

class PassageTokenizer
{
private:
	string section;
	istringstream word;
	vector<string> VectSect;
public:
	PassageTokenizer(string str);
	SectionToken nextSection();
	bool hasNextSection();
};
#endif

