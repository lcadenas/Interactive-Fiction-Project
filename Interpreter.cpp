#include "Interpreter.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "storytokenizer.h"

using namespace std;

Interpreter::Interpreter(string file)
{
	//makeStok();
	StoryTokenizer Story(file);
	int pass = 0;
	while (Story.hasNextPassage())
	{
		PassageToken pTok = Story.nextPassage();
		
		passage[pTok.getName()] = pass;
		pass++;

		PassVect.push_back(pTok);
		//cout << "Passage " << pass << ":  " << endl;
		PassageTokenizer Pt(pTok.getText());
	}
}

/*void Interpreter::makeStok() {

	StoryTokenizer(trueStory);


}*/