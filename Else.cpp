#include <string>
#include <iostream>
#include "Else.h"

using namespace std;

Else::Else(string sect) {

	int start = sect.find("[") + 1;
	int end = sect.find("]");
	varElse = sect.substr(start, end - start);
}