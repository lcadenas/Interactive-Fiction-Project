#include <vector>
#include <string>
#include <iostream>
#include "Set.h"
using namespace std;

Set::Set(string sect) {
	int found = sect.find("$");
	int end = sect.find(" ", found + 1);
	varSet = sect.substr(found + 1, end - found);
	if (sect.find("true") != string::npos)
		valueSet = true;
	else
		valueSet = false;
}