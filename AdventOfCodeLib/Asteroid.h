#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

using namespace::std;

#include <string>
#include <vector>
#include <map>

#pragma once
class ADVENTOFCODELIB_API Asteroid
{
public:
	Asteroid(int y, int x, int id) {
		Id = id;
		X = x;
		Y = y;
		NumVisibleAsteroids = 0;
	}
	int Id;
	int X;
	int Y;
	int NumVisibleAsteroids;
	double Sine;
	double Cosine;
	friend bool operator==(const Asteroid& lhs, const Asteroid& rhs);
	friend bool operator<(const Asteroid& lhs, const Asteroid& rhs)
	{
		return lhs.Sine > rhs.Sine;
	}
	int getNumVisibleAsteroids(map<int, vector<int>> asteroidBelt);
	bool IsSeenBy(int x, int y, std::map<int, std::vector<int>>& asteroidBelt);
};

