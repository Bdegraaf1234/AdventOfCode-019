#include "AsteroidBelt.h"
#include <algorithm>

Asteroid AsteroidBelt::GetBestPosition()
{
	int maxNum = 0;
	int maxIdx = 0;
	for (size_t i = 0; i < AsteroidList.size(); i++)
	{
		int ans = AsteroidList[i].getNumVisibleAsteroids(AsteroidPositions);
		if (ans > maxNum)
		{
			maxNum = ans;
			maxIdx = i;
		}
	}
	return AsteroidList[maxIdx];
}

vector<Asteroid> AsteroidBelt::DestroyAll(Asteroid start)
{
	vector<Asteroid> destroyed;
	int startX = start.X;
	int startY = start.Y;

	int xFocus = startX;
	int yFocus = startY - 1;
	for (size_t i = 0; i < AsteroidList.size(); i++)
	{
		double attachedSide = (double)startX - (double)AsteroidList[i].X;
		double oppositeSide = (double)startY - (double)AsteroidList[i].Y;
		double longSide = sqrt(pow(attachedSide, 2) + pow(oppositeSide, 2));
		AsteroidList[i].Sine = round(oppositeSide / longSide * 100000) / 100000;
		AsteroidList[i].Cosine = round(attachedSide / longSide * 100000) / 100000;
		if (AsteroidList[i].X < startX)
		{
			AsteroidList[i].Sine = -AsteroidList[i].Sine;
		}
	}
	AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), start));
	std::sort(AsteroidList.begin(), AsteroidList.end());
	while (!AsteroidList.empty()) {
		vector<Asteroid> destroyedIt;
		for (size_t i = 0; i < AsteroidList.size(); i++)
		{
			Asteroid currentAsteroid = AsteroidList[i];
			if (currentAsteroid.X >= startX)
			{
				if (currentAsteroid.IsSeenBy(startX, startY, AsteroidPositions))
				{
					destroyed.push_back(currentAsteroid);
					destroyedIt.push_back(currentAsteroid);
				}
			}
		}	
		for (size_t i = 0; i < AsteroidList.size(); i++)
		{
			Asteroid currentAsteroid = AsteroidList[i];
			if (currentAsteroid.X < startX)
			{
				if (currentAsteroid.IsSeenBy(startX, startY, AsteroidPositions))
				{
					destroyed.push_back(currentAsteroid);
					destroyedIt.push_back(currentAsteroid);
				}
			}
		}
		for (size_t i = 0; i < destroyedIt.size(); i++)
		{
			Asteroid currentAsteroid = destroyedIt[i];
			AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), currentAsteroid));
			AsteroidPositions[currentAsteroid.Y].erase(find(AsteroidPositions[currentAsteroid.Y].begin(), AsteroidPositions[currentAsteroid.Y].end(), currentAsteroid.X));
		}
	}
	return destroyed;
}