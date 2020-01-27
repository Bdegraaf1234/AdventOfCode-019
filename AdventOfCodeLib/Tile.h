#pragma once
#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

using namespace::std;

#include <string>
#include <vector>
#include <map>

class ADVENTOFCODELIB_API Tile
{
public:
	int X;
	int Y;
	char Id;
	Tile(int tileInstructions[]) {
		X = tileInstructions[0];
		Y = tileInstructions[1];
		if (tileInstructions[2] == 0)
		{
			Id = ' ';
		}
		else if (tileInstructions[2] == 1)
		{
			Id = '|';
		}
		else if (tileInstructions[2] == 2)
		{
			Id = 'D';
		}
		else if (tileInstructions[2] == 3)
		{
			Id = '_';
		}
		else if (tileInstructions[2] == 4)
		{
			Id = 'D';
		}
	}
};

