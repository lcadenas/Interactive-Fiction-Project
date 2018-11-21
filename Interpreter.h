#ifndef __INTERPRETER_H
#define __INTERPRETER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "storytokenizer.h"
using namespace std; 

class Interpreter
{
private:
	//StoryTokenizer Story;
	//PassageToken pToken;
	//PassageTokenizer Pt;
	//string trueStory;
	//SectionToken Stok;
	unordered_map<string , int > passage;
	unordered_map< string, bool> variable;
	vector<PassageToken> PassVect;
	//Link Lk;

public:
	Interpreter(string file);
	//void ReadStory(PassageToken);
	//void makeStok();
};
#endif