#include "Asteroid.h"
#include <string>
#include <vector>
#include <map>
#include <math.h>


int Asteroid::getNumVisibleAsteroids(map<int, vector<int>> asteroidBelt)
{
	map<int, vector<int>>::iterator it;
	for (it = asteroidBelt.begin(); it != asteroidBelt.end(); it++)
	{
		for (size_t yIdx = 0; yIdx < it->second.size(); yIdx++)
		{
			int y = it->first;
			int x = it->second[yIdx];
			;
			if (IsSeenBy(x, y, asteroidBelt)) {
				NumVisibleAsteroids++;
			};
		}
	}
	return NumVisibleAsteroids;
}

bool Asteroid::IsSeenBy(int x, int y, std::map<int, std::vector<int>>& asteroidBelt)
{
	int deltaX = x - X;
	int deltaY = y - Y;

	if (deltaY == 0 && deltaX == 0)
	{
		return false;
	}

	bool add = true;
	if (deltaY == 0)
	{
		if (deltaX > 0)
		{
			for (size_t i = 1; i < deltaX; i++)
			{
				if (std::find(asteroidBelt[Y].begin(), asteroidBelt[Y].end(), X + i) != asteroidBelt[Y].end())
				{
					add = false;
					break;
				}
			}
		}
		if (deltaX < 0)
		{
			for (int i = -1; i > deltaX; i--)
			{
				if (std::find(asteroidBelt[Y].begin(), asteroidBelt[Y].end(), X + i) != asteroidBelt[Y].end())
				{
					add = false;
					break;
				}
			}
		}
	}
	if (deltaX == 0)
	{
		if (deltaY > 0)
		{
			for (size_t i = 1; i < deltaY; i++)
			{
				if (std::find(asteroidBelt[Y + i].begin(), asteroidBelt[Y + i].end(), X) != asteroidBelt[Y + i].end())
				{
					add = false;
					break;
				}
			}
		}
		if (deltaY < 0)
		{
			for (int i = -1; i > deltaY; i--)
			{
				if (std::find(asteroidBelt[Y + i].begin(), asteroidBelt[Y + i].end(), X) != asteroidBelt[Y + i].end())
				{
					add = false;
					break;
				}
			}
		}
	}
	//for positive
	if (deltaY > 0)
	{
		for (size_t i = 1; i < deltaY; i++)
		{
			double xCoordinate = ((double)deltaX / (double)deltaY * (double)i);
			if ((xCoordinate == floor(xCoordinate))) {
				if (std::find(asteroidBelt[Y + i].begin(), asteroidBelt[Y + i].end(), X + xCoordinate) != asteroidBelt[Y + i].end())
				{
					add = false;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = -1; i > deltaY; i--)
		{
			double xCoordinate = ((double)deltaX / (double)deltaY * (double)i);
			if ((xCoordinate == floor(xCoordinate))) {
				if (std::find(asteroidBelt[Y + i].begin(), asteroidBelt[Y + i].end(), X + xCoordinate) != asteroidBelt[Y + i].end())
				{
					add = false;
					break;
				}
			}
		}
	}
	return add;
}

bool operator==(const Asteroid& lhs, const Asteroid& rhs)
{
	return lhs.Id == rhs.Id;
}
