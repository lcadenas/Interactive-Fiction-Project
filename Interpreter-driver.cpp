#include <iostream>
#include <string>
#include "storytokenizer.h"
#include "Interpreter.h"
using namespace std;

int main()
{
	string line, story, realStory;

	getline(cin, line);
	while (cin && line != "</html>")
	{
		story += line + '\n';
		getline(cin, line);
	}


	unsigned start = story.find("<tw-storydata");

	unsigned stop = story.find("</tw-storydata>") + 14;

	realStory = story.substr(start, stop - start + 1);

	Interpreter(realStory);

	return 0;
}