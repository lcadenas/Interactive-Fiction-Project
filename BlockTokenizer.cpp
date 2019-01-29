#include "BlockTokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "storytokenizer.h"
using namespace std;

BlockTokenizer::BlockTokenizer(string str)
{
	int count1 = 0, count2 = 0, countA = 0, countB = 0, countLink1 = 0, countLink2 = 0;
	section = str.substr(1, str.length() - 2);

	section.insert(0, 1, '|');

	for (int i = 0; i < section.size(); i++)
	{
		if (section[i] == '(')
		{
			if (count1 == count2)
			{
				if (section[i - 1] != '|') {

					section.insert(i, 1, '|');
					i++;
				}
			}
		}

		else if (section[i] == ')')
		{
			if (count1 == count2)
				section.insert(i + 1, 1, '|');
		}

		else if (section[i] == '[')
		{
			if (count1 == count2)
			{
				if (section[i - 1] == '|')
					count1++, countA++;
				else
				{
					if (section[i + 1] == '[')
					{
						section.insert(i, 1, '|');
						i += 2;
						countLink1++;
					}
				}
			}
			else
			{
				if (section[i - 1] == ')')
					countA++;
				else
				{
					countLink1++;
					i++;
				}

			}
		}

		else if (section[i] == ']')
		{
			if (count1 == count2)
			{
				if (section[i + 1] == ']')
				{
					section.insert(i + 2, 1, '|');
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
					section.insert(i + 1, 1, '|');
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

	input.str(section);
	while (getline(input, blocksec, '|'))
	{
		if (blocksec != "\n")
			blockVect.push_back(blocksec);
		else
			continue;

	}
}
bool BlockTokenizer::hasNextBlockSection()
{
	if (blockVect.size() != 0)
		return true;
	else
		return false;
}

SectionToken BlockTokenizer::nextBlockSection()
{
	if (hasNextBlockSection())
	{
		SectionToken stoken(blockVect.at(0));
		blockVect.erase(blockVect.begin());
		return stoken;
	}
	else
	{
		SectionToken stoken("");
		return stoken;
	}
}
