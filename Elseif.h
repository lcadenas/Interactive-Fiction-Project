#include <string>
#include <iostream>

using namespace std;

class ElseiF
{
private:
	string varElseif;
	bool valueElseif;

public:
	ElseiF(string sect);
	string getText() const { return varElseif; }
	bool getBool() const { return valueElseif; }
};