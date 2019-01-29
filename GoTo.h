#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GoTo
{
private:
	string newPass;
public:
	GoTo(string sect);
	string getNewPAss() const { return newPass; }
};