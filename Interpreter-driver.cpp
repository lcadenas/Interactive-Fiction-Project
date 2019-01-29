#include <iostream>
#include <string>
#include "storytokenizer.h"
#include "Interpreter.h"
#include <fstream>
using namespace std;

int main()
{
	string line, story, realStory, myStory;
	//cout << 
	getline(cin, myStory);
	ifstream myFile;
	myFile.open(myStory);


	getline(myFile, line);
	while (myFile.is_open() && line != "</html>")
	{
		story += line + '\n';
		getline(myFile, line);
	}

	
	unsigned start = story.find("<tw-storydata");

	unsigned stop = story.find("</tw-storydata>") + 14;

	realStory = story.substr(start, stop - start + 1);

	Interpreter it(realStory);

	system("pause");
	return 0;
}