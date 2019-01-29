#include <string>
#include <iostream>

using namespace std;

class iF
{
private:

	string varIf;
	bool valIf;
	string text;
public:
	iF(string sect);
	string getText() const { return varIf; }
	bool getBool() const { return valIf; }
};