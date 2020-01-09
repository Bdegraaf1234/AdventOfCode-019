#pragma once
#include <vector>
#include <map>
#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif
#include "IntCodeProcessor.h"

using namespace::std;

class ADVENTOFCODELIB_API HullPainter
{
public:
	bool Grid[1000][1000] = { {} };
	int XCoordinate = 500;
	int YCoordinate = 500;
	map<int, vector<int>> Painted;
	int NumPainted = 0;
	int Direction = 0;
	void Turn(bool clockWise);
	bool Move(bool clockWise, bool outColor);
	int Run(IntCodeProcessor processor, bool input);
	void WriteOut(string path);
	int Run(IntCodeProcessor processor);
};

