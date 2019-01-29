#pragma once
#include "storytokenizer.h"
#include "passagetoken.h"
#include "sectiontoken.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Link
{
private:
	string lK;
	string content = "";
public:
	Link(string sect);
	string getText() const { return content; }
	string getlK() const { return lK; }

	//Type_t getType() const;
	//string getPassage() const;
};