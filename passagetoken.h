#ifndef __PASSAGETOKEN_H
#define __PASSAGETOKEN_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PassageToken
{
private:
    string text;
	string name;
public:
    PassageToken(string body);
    string getText() const;
	string getName() const;
};
#endif

