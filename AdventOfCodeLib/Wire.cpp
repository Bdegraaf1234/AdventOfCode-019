#include "Wire.h"

#include <algorithm>

using namespace::std;

void Wire::SetPath(vector<string> path)
{
	Route = path;
	int x = 0;
	int y = 0;
	for (size_t i = 0; i < path.size(); i++)
	{
		string instruction = path[i];
		if (instruction[0] == 'U')
		{
			int numSteps = std::stoi(instruction.substr(1));
			for (size_t j = 0; j < numSteps; j++)
			{
				y++;
				if (std::count(Positions[x].begin(), Positions[x].end(), y) == 0)
				{
					Positions[x].push_back(y);
				}
			}
		}
		if (instruction[0] == 'D')
		{
			int numSteps = std::stoi(instruction.substr(1));
			for (size_t j = 0; j < numSteps; j++)
			{
				y--;
				if (std::count(Positions[x].begin(), Positions[x].end(), y) == 0)
				{
					Positions[x].push_back(y);
				}
			}
		}
		if (instruction[0] == 'L')
		{
			int numSteps = std::stoi(instruction.substr(1));
			for (size_t j = 0; j < numSteps; j++)
			{
				x--;
				if (std::count(Positions[x].begin(), Positions[x].end(), y) == 0)
				{
					Positions[x].push_back(y);
				}
			}
		}
		if (instruction[0] == 'R')
		{
			int numSteps = std::stoi(instruction.substr(1));
			for (size_t j = 0; j < numSteps; j++)
			{
				x++;
				if (std::count(Positions[x].begin(), Positions[x].end(), y) == 0)
				{
					Positions[x].push_back(y);
				}
			}
		}
	}
}

map<int, vector<int>> Wire::GetOverlapMap(Wire otherWire)
{
	map<int, vector<int>> overlaps;
	for (auto& XThenYs : Positions)
	{
		int AX = XThenYs.first;
		vector<int> AYs = XThenYs.second;
		for (size_t i = 0; i < XThenYs.second.size(); i++)
		{
			if (std::count(otherWire.Positions[AX].begin(), otherWire.Positions[AX].end(), AYs[i]))
			{
				overlaps[AX].push_back(AYs[i]);
			}
		}
	}
	return overlaps;
}

int Wire::GetNumSteps(int xTarget, int yTarget)
{
	int x = 0;
	int y = 0;
	int totalNumSteps = 0;
	for (size_t i = 0; i < Route.size(); i++)
	{
		string instruction = Route[i];
		if (instruction[0] == 'U')
		{
			int numSteps = std::stoi(instruction.substr(1));
			for (size_t j = 0; j < numSteps; j++)
			{
				y++;
				totalNumSteps++;
				if (x == xTarget && y == yTarget)
				{
					return totalNumSteps;
				}
			}
		}
		if (instruction[0] == 'D')
		{
			int numSteps = std::stoi(instruction.substr(1));
			for (size_t j = 0; j < numSteps; j++)
			{
				y--;
				totalNumSteps++;
				if (x == xTarget && y == yTarget)
				{
					return totalNumSteps;
				}
			}
		}
		if (instruction[0] == 'L')
		{
			int numSteps = std::stoi(instruction.substr(1));
			for (size_t j = 0; j < numSteps; j++)
			{
				x--;
				totalNumSteps++;
				if (x == xTarget && y == yTarget)
				{
					return totalNumSteps;
				}
			}
		}
		if (instruction[0] == 'R')
		{
			int numSteps = std::stoi(instruction.substr(1));
			for (size_t j = 0; j < numSteps; j++)
			{
				x++;
				totalNumSteps++;
				if (x == xTarget && y == yTarget)
				{
					return totalNumSteps;
				}
			}
		}
	}
}
