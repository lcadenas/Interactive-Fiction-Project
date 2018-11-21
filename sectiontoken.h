#ifndef __SECTIONTOKEN_H
#define __SECTIONTOKEN_H


#include <iostream>
#include <string>
using namespace std;

enum Type_t {LINK, GOTO, SET, IF, ELSEIF,ELSE, BLOCK, TEXT};

class SectionToken
{
private:    
    Type_t type;
    string sectiontext;
public:   
    SectionToken(string sect);
    string getText();
    Type_t getType();
};
#endif

