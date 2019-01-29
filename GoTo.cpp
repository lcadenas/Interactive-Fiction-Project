#include <iostream>
#include <string>
#include <vector>
#include "GoTo.h"
using namespace std;

GoTo::GoTo(string sect) {
	int found = sect.find("&quot");
	found = found + 7;
	int end = sect.find("&", found + 2);
	newPass = sect.substr(found, end - found);
}