#include "ElectricalGrid.h"
#include "Parsing.h"

#include <cstdlib>
using namespace std;

ElectricalGrid::ElectricalGrid(string path)
{
	vector<vector<string>> input = Parsing::ParseInputDay3(path);
	WireA = Wire();
	WireA.SetPath(input[0]);
	WireB = Wire();
	WireB.SetPath(input[1]);
}

int ElectricalGrid::GetShortestManhattanDistance()
{
	map<int, vector<int>> overlapsA = WireA.GetOverlapMap(WireB);
	int minDistance = -1;
	for (auto& XThenYs : overlapsA)
	{
		int AX = XThenYs.first;
		vector<int> AYs = XThenYs.second;
		for (size_t i = 0; i < XThenYs.second.size(); i++)
		{
			int curDistance = abs(AX) + abs(AYs[i]);
			if (curDistance < minDistance || minDistance == -1)
			{
				minDistance = curDistance;
			}
		}
	}
	return minDistance;
}

int ElectricalGrid::GetLowestNumSteps()
{
	map<int, vector<int>> overlapsA = WireA.GetOverlapMap(WireB);
	int minNumSteps= -1;
	for (auto& XThenYs : overlapsA)
	{
		int AX = XThenYs.first;
		vector<int> AYs = XThenYs.second;
		for (size_t i = 0; i < XThenYs.second.size(); i++)
		{
			int curNumSteps = WireA.GetNumSteps(AX, AYs[i]) + WireB.GetNumSteps(AX, AYs[i]);
			if (curNumSteps < minNumSteps || minNumSteps == -1)
			{
				minNumSteps = curNumSteps;
			}
		}
	}
	return minNumSteps;
}
