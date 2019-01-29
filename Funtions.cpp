#include "storytokenizer.h"
#include "passagetoken.h"
#include "sectiontoken.h"
#include "passagetokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


StoryTokenizer::StoryTokenizer(string input)
{
	//story.str(input);
	//string word = "</tw-storydata>";
	int position = 0;
	int start = input.find("<tw-passagedata", position);

	while (start != string::npos)
	{
		unsigned end = input.find("</tw-passagedata>", start) + 17;
		line = input.substr(start, end - start);
		passvect.push_back(line);
		position = end;
		start = input.find("<tw-passagedata", position);
	}
}

bool StoryTokenizer::hasNextPassage()
{
	if (passvect.size() != 0)
		return true;
	else
		return false;
}

PassageToken StoryTokenizer::nextPassage()
{
	if (hasNextPassage())
	{
		PassageToken ptoken(passvect.at(0));
		passvect.erase(passvect.begin());
		return ptoken;
	}
	else
	{
		PassageToken ptoken("");
		return ptoken;
	}
}

SectionToken::SectionToken(string sect)
{
	if (sect == "")
		sectiontext = "";
	else
	{
		sectiontext = sect;

		if (sectiontext[0] == '(')
		{
			if (sect.find("go-to:") != string::npos)
				type = GOTO;
			else if (sect.find("set:") != string::npos)
				type = SET;
			else if (sect.find("(if:") != string::npos)
				type = IF;
			else if (sect.find("else-if:") != string::npos)
				type = ELSEIF;
			else if (sect.find("else:") != string::npos)
				type = ELSE;
		}
		else if (sectiontext[0] == '[')
		{
			if (sectiontext[1] == '[')
				type = LINK;
			else
				type = BLOCK;
		}
		else
			type = TEXT;
	}
}

string SectionToken::getText()
{
	return sectiontext;
}

Type_t SectionToken::getType()
{
	return type;
}

PassageTokenizer::PassageTokenizer(string str)
{
	int count1 = 0, count2 = 0, countA = 0, countB = 0, countLink1 = 0, countLink2 = 0;

	str.insert(1, 1, '|');

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			if (count1 == count2)
			{
				if (str[i - 1] != '|') {

					str.insert(i, 1, '|');
					i++;
				}
			}
		}

		else if (str[i] == ')')
		{
			if (count1 == count2)
				str.insert(i + 1, 1, '|');
		}

		else if (str[i] == '[')
		{
			if (count1 == count2)
			{
				if (str[i - 1] == '|')
					count1++, countA++;
				else
				{
					if (str[i + 1] == '[')
					{
						str.insert(i, 1, '|');
						i += 2;
						countLink1++;
					}
				}
			}
			else
			{
				if (str[i - 1] == ')')
					countA++;
				else
				{
					countLink1++;
					i++;
				}

			}
		}

		else if (str[i] == ']')
		{
			if (count1 == count2)
			{
				if (str[i + 1] == ']')
				{
					str.insert(i + 2, 1, '|');
					countLink2++;
					i += 2;
				}
			}
			else
			{
				if (countLink1 - countLink2 == 1)
				{
					countLink2++;
					i++;
				}

				else if (countA - countB == 1)
				{
					str.insert(i + 1, 1, '|');
					countB++;
					count2++;
				}

				else
				{
					countB++;
				}
			}
		}
	}

	word.str(str);
	while (getline(word, section, '|'))
	{
		if (section != "\n")
			VectSect.push_back(section);
		else
			continue;

	}
}
bool PassageTokenizer::hasNextSection()
{
	if (VectSect.size() != 0)
		return true;
	else
		return false;
}

SectionToken PassageTokenizer::nextSection()
{
	if (hasNextSection())
	{
		SectionToken stoken(VectSect.at(0));
		VectSect.erase(VectSect.begin());
		return stoken;
	}
	else
	{
		SectionToken stoken("");
		return stoken;
	}
}

PassageToken::PassageToken(string body)
{
	if (body == "")
		text = "";
	else
	{
		int pos = body.find("name") + 6;
		name = body.substr(pos, body.find('"', pos) - pos);
		unsigned start = body.find_first_of('>') + 1;
		unsigned end = body.find("</tw-passagedata");
		text = "\n" + body.substr(start, end - start) + "\n";
	}
}

string PassageToken::getText() const
{
	return text;
}

string PassageToken::getName() const
{
	return name;
}