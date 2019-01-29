#include "storytokenizer.h"
#include "passagetoken.h"
#include "sectiontoken.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include"Link.h"

using namespace std;

Link::Link(string sect) {
	int found = 0;


	if (sect.find("&gt") != string::npos) {
		found = sect.find("-");
		content = sect.substr(2, found - 2);
		lK = sect.substr(found + 5, sect.length() - (found + 7));
	}
	else
		lK = sect.substr(2, sect.length() - 4);
}