#include "Interpreter.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "storytokenizer.h"
#include "Set.h"
#include "GoTo.h"
#include "Link.h"
#include "IF.h"
#include "Elseif.h"
#include "Else.h"

using namespace std;

Interpreter::Interpreter(string file)
{
	StoryTokenizer Story(file);
	int pass = 0;
	while (Story.hasNextPassage())
	{
		PassageToken pTok = Story.nextPassage();

		passage[pTok.getName()] = pass;
		pass++;

		PassVect.push_back(pTok);
		
	}

	readStory(PassVect[0]);

}

void Interpreter::readStory(PassageToken pTok)
{
	PassageTokenizer Pt(pTok.getText());
	Link *Lk;
	vector<Link*> linkVect;
	iF* ifcommand;
	GoTo* gTcommand;
	Set* setcommand;
	ElseiF* elseifcommand;
	Else* elsecommand;

	while (Pt.hasNextSection())
	{
		SectionToken stok = Pt.nextSection();

		switch (stok.getType())
		{
		case LINK:
			Lk = new Link(stok.getText());
			if (Lk->getText() == "") {

				cout << Lk->getlK();
			}
			else {

				cout << Lk->getText();
			}
			linkVect.push_back(Lk);
			break;
		case SET:
			setcommand = new Set(stok.getText());
			variable[setcommand->getVarSet()] = setcommand->getVal();
			break;
		case GOTO:
			gTcommand = new GoTo(stok.getText());
			readStory(PassVect[passage[gTcommand->getNewPAss()]]);
			break;
		case IF:
			ifcommand = new iF(stok.getText());
			if (variable[ifcommand->getText()] == ifcommand->getBool()) {
				enterblock = true;
			}
			else
				enterblock = false;
			break;
		case ELSEIF:
			elseifcommand = new ElseiF(stok.getText());
			if (variable[elseifcommand->getText()] == elseifcommand->getBool())
				enterblock = true;
			else
				enterblock = false;
			break;
		case ELSE:
			elsecommand = new Else(stok.getText());
			if (enterblock == false)
				enterblock = true;
			else
				enterblock = false;
			break;
		case BLOCK:
			if (enterblock != true)
				break;
			else {
				readStory(BlockTokenizer(stok.getText()));
			}
			break;
		case TEXT:
			cout << stok.getText();
			break;
		}
	}

	if (linkVect.size() < 1) {
	}
	else {

		cout << endl << endl;

		cout << "Select One Corresponding Option:" << endl;

		for (int i = 0; i < linkVect.size(); i++) {

			if (linkVect[i]->getText() == "") {

				cout << i << " " << linkVect[i]->getlK() << endl;
			}
			else {

				cout << i << " " << linkVect[i]->getText() << endl;
			}
			
		}
		int i = 0;
		cin >> i;
		
		readStory(PassVect[passage[linkVect[i]->getlK()]]);
		
	} 
}


void Interpreter::readStory(BlockTokenizer bTok)
{
	Link *Lk;
	vector<Link*> linkVect;
	iF* ifcommand;
	GoTo* gTcommand;
	Set* setcommand;
	ElseiF* elseifcommand;
	Else* elsecommand;

	while (bTok.hasNextBlockSection())
	{
		SectionToken stok = bTok.nextBlockSection();

		switch (stok.getType())
		{
		case LINK:
			Lk = new Link(stok.getText());
			linkVect.push_back(Lk);
			break;
		case SET:
			setcommand = new Set(stok.getText());
			variable[setcommand->getVarSet()] = setcommand->getVal();
			break;
		case GOTO:
			gTcommand = new GoTo(stok.getText());
			readStory(PassVect[passage[gTcommand->getNewPAss()]]);
			break;
		case IF:
			ifcommand = new iF(stok.getText());
			if (variable[ifcommand->getText()] == ifcommand->getBool())
				enterblock = true;
			else
				enterblock = false;
			break;
		case ELSEIF:
			elseifcommand = new ElseiF(stok.getText());
			if (variable[elseifcommand->getText()] == elseifcommand->getBool())
				enterblock = true;
			else
				enterblock = false;
			break;
		case ELSE:
			cout << "  Else:  ";
			elsecommand = new Else(stok.getText());
			if (enterblock == false)
				enterblock = true;
			else
				enterblock = false;
			break;
		case BLOCK:
			if (enterblock != true)
				break;
			else {
				readStory(BlockTokenizer(stok.getText()));
			}
			break;
		case TEXT:
			cout << stok.getText();
			break;
		}
	}
	if (linkVect.size() < 1) {
	}
	else {

		cout << endl << endl;

		cout << "Select One Corresponding Option:" << endl;

		for (int i = 0; i < linkVect.size(); i++) {

			if (linkVect[i]->getText() == "") {

				cout << i << " " << linkVect[i]->getlK() << endl;
			}
			else {

				cout << i << " " << linkVect[i]->getText() << endl;
			}

		}
		int i = 0;
		cin >> i;

		readStory(PassVect[passage[linkVect[i]->getlK()]]);

	}
}


