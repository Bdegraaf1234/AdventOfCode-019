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
#include "Asteroid.h"

#pragma once
class ADVENTOFCODELIB_API AsteroidBelt
{
public:
	AsteroidBelt(map<int, vector<int>> belt) {
		AsteroidPositions = belt;
		map<int, vector<int>>::iterator YThenXs;
		int id = 0;
		MaxX = 0;
		for (YThenXs = AsteroidPositions.begin(); YThenXs != AsteroidPositions.end(); YThenXs++)
		{
			for (size_t x = 0; x < YThenXs->second.size(); x++)
			{
				AsteroidList.push_back(Asteroid(YThenXs->first, YThenXs->second[x], id));
				id++;
				MaxY = YThenXs->first;
				if (YThenXs->second[x] > MaxX)
				{
					MaxX = YThenXs->second[x];
				}
			}
		}
	};
	map<int, vector<int>> AsteroidPositions;
	vector<Asteroid> AsteroidList;
	Asteroid GetBestPosition();
	vector<Asteroid> DestroyAll(Asteroid start);
	int MaxX;
	int MaxY;
};

