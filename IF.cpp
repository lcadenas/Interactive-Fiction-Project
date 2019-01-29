#include <string>
#include <iostream>
#include "IF.h"

using namespace std;

iF::iF(string sect) { 
	int fBegin;
	int fEnd;
	string nString;


	fBegin = sect.find("$");
	fEnd = sect.find(' ', fBegin);
	varIf = sect.substr(fBegin + 1, fEnd - fBegin);
	fEnd = sect.find(")");
	//nString = sect.substr(fEnd);
	if (sect.find("true") != string::npos)
		valIf = true;
	else
		valIf = false;
}