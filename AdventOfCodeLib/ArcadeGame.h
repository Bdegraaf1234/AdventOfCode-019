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
#include "Tile.h"
#include "IntCodeProcessor.h"

class ADVENTOFCODELIB_API ArcadeGame
{
public:
	void Init(IntCodeProcessor cpu);
	void Display();
	void DisplayScore(int score);
	void Alter(Tile newTile);

	char Grid[200][200] = { {} };
};

