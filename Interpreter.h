#ifndef __INTERPRETER_H
#define __INTERPRETER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "storytokenizer.h"
#include "BlockTokenizer.h"
using namespace std;

class Interpreter
{
private:

	unordered_map<string, int > passage;
	unordered_map< string, bool> variable;
	vector<PassageToken> PassVect;
	bool enterblock = true;

public:
	Interpreter(string file);
	void readStory(PassageToken ptok);
	void readStory(BlockTokenizer btok);
};
#endif