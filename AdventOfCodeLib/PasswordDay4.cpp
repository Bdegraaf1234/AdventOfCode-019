#include "PasswordDay4.h"
#include <algorithm>

using namespace::std;

PasswordDay4::PasswordDay4(int num)
{
	Password[5] = num % 10;
	Password[4] = num / 10 % 10;
	Password[3] = num / 100 % 10;
	Password[2] = num / 1000 % 10;
	Password[1] = num / 10000 % 10;
	Password[0] = num / 100000 % 10;
}

bool PasswordDay4::Check()
{
	bool res = false;
	if (std::is_sorted(Password, Password + 6))
	{
		bool intermediateRes = false;
		for (size_t i = 0; i < 5; i++)
		{
			if (Password[i] == Password[i + 1])
			{
				if (i == 0)
				{
					if (Password[i + 1] != Password[i + 2])
					{
						intermediateRes = true;
						break;
					}
				}
				if (i == 4)
				{
					if (Password[i] != Password[i - 1])
					{
						intermediateRes = true;
						break;
					}
				}
				else
				{
					if (Password[i + 1] != Password[i + 2] && Password[i] != Password[i - 1])
					{
						intermediateRes = true;
						break;
					}
				}
			}
		}
		res = intermediateRes;
	}
	return res;
}

int PasswordDay4::GetNumPossibilities(int floor, int ceiling)
{
	int numCorrect = 0;
	for (size_t i = floor; i <= ceiling; i++)
	{
		PasswordDay4 pw = PasswordDay4(i);
		if (pw.Check())
		{
			numCorrect++;
		}
	}
	return numCorrect;
}
