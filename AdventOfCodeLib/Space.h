#pragma once
#include "Moon.h"
#include <vector>
#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif


using namespace std;

class ADVENTOFCODELIB_API Space
{
public:
	long long Time = 0;
	vector<Moon> Moons;
	void ApplyGravity(vector<int> axes);
	int GetPeriod(int axis, int moon);
	void AdvanceTime(vector<int> axes);
	int GetTotalEnergy();
};

