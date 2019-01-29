#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Set
{
private:
	string varSet;
	bool valueSet;
public:
	Set(string sect);
	bool getVal() { return valueSet; }
	string getVarSet() { return varSet; }
};
