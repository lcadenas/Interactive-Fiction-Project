#include <string>
#include <iostream>
#include "Elseif.h"

using namespace std;
ElseiF::ElseiF(string sect) {
	int fBegin;
	int fEnd;
	string nString;

	if (sect.find("(else-if:") != string::npos) {
		fBegin = sect.find("$");
		fEnd = sect.find(' ', fBegin);
		varElseif = sect.substr(fBegin + 1, fEnd - fBegin);

	}
	fEnd = sect.find(")");
	nString = sect.substr(0, fEnd);
	if (nString.find("true") != string::npos)
		valueElseif = true;
	else
		valueElseif = false;
}
