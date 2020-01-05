#include "AsteroidBelt.h"

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
		AsteroidList[i].Sine = oppositeSide / longSide;
		AsteroidList[i].Cosine = attachedSide / longSide;
	}
	AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), start));

	while (!AsteroidList.empty()) {
		//delete right above;
	for (size_t i = 0; i < AsteroidList.size(); i++)
		{
			Asteroid currentAsteroid = AsteroidList[i];
			if (currentAsteroid.X == startX && currentAsteroid.Y < startY)
			{
				if (currentAsteroid.IsSeenBy(startX, startY, AsteroidPositions))
				{
					destroyed.push_back(currentAsteroid);
					AsteroidPositions[currentAsteroid.Y].erase(find(AsteroidPositions[currentAsteroid.Y].begin(), AsteroidPositions[currentAsteroid.Y].end(), currentAsteroid.X));
					AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), currentAsteroid));
					break;
				}
			}
		}

		double maxSin = 1;
		//pass quadrant topright
		while (1) {
			vector<int> targetIdx = { -1 };
			double maxSin2 = 0;
			for (size_t i = 0; i < AsteroidList.size(); i++)
			{
				Asteroid currentAsteroid = AsteroidList[i];
				if (currentAsteroid.X > startX && currentAsteroid.Y < startY)
				{
					if (currentAsteroid.Sine >= maxSin2 && currentAsteroid.Sine < maxSin)
					{
						//FIXME: sine function is not accurate enough.
						if (currentAsteroid.Sine == maxSin2)
						{
							if (targetIdx[0] == -1) {
								targetIdx[0] = i;
							}
							else
							{
								targetIdx.push_back(i);
							}
						}
						else
						{
							targetIdx = { (int)i };
						}
						maxSin2 = currentAsteroid.Sine;

					}
				}
			}
			if (targetIdx[0] != -1)
			{
				while (1) {
					if (AsteroidList[targetIdx[0]].IsSeenBy(startX, startY, AsteroidPositions))
					{
						maxSin = AsteroidList[targetIdx[0]].Sine;
						destroyed.push_back(AsteroidList[targetIdx[0]]);
						AsteroidPositions[AsteroidList[targetIdx[0]].Y].erase(find(AsteroidPositions[AsteroidList[targetIdx[0]].Y].begin(), AsteroidPositions[AsteroidList[targetIdx[0]].Y].end(), AsteroidList[targetIdx[0]].X));
						AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), AsteroidList[targetIdx[0]]));
						break;
					}
					else
					{
						targetIdx.erase(targetIdx.begin());
					}
				}
			}
			else
			{
				break;
			}
		}

		//delete right beside;
		for (size_t i = 0; i < AsteroidList.size(); i++)
		{
			Asteroid currentAsteroid = AsteroidList[i];
			if (currentAsteroid.X > startX && currentAsteroid.Y == startY)
			{
				if (currentAsteroid.IsSeenBy(startX, startY, AsteroidPositions))
				{
					destroyed.push_back(currentAsteroid);
					AsteroidPositions[currentAsteroid.Y].erase(find(AsteroidPositions[currentAsteroid.Y].begin(), AsteroidPositions[currentAsteroid.Y].end(), currentAsteroid.X));
					AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), currentAsteroid));
					break;
				}
			}
		}

		double maxCos = -1;
		// pass lowerright quadrant;
		while (1) {
			vector<int> targetIdx = { -1 };
			double maxcos2 = 0;
			for (size_t i = 0; i < AsteroidList.size(); i++)
			{
				Asteroid currentAsteroid = AsteroidList[i];
				if (currentAsteroid.X > startX&& currentAsteroid.Y > startY)
				{
					if (currentAsteroid.Cosine <= maxcos2 && currentAsteroid.Cosine > maxCos)
					{
						maxcos2 = currentAsteroid.Cosine;
						if (targetIdx[0] == -1) {
							targetIdx[0] = i;
						}
						else
						{
							targetIdx.push_back(i);
						}
					}
				}
			}
			if (targetIdx[0] != -1)
			{
				while (1) {
					if (AsteroidList[targetIdx[0]].IsSeenBy(startX, startY, AsteroidPositions))
					{
						maxCos = AsteroidList[targetIdx[0]].Cosine;
						destroyed.push_back(AsteroidList[targetIdx[0]]);
						AsteroidPositions[AsteroidList[targetIdx[0]].Y].erase(find(AsteroidPositions[AsteroidList[targetIdx[0]].Y].begin(), AsteroidPositions[AsteroidList[targetIdx[0]].Y].end(), AsteroidList[targetIdx[0]].X));
						AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), AsteroidList[targetIdx[0]]));
						break;
					}
					else
					{
						targetIdx.erase(targetIdx.begin());
					}
				}
			}
			else
			{
				break;
			}
		}

		//delete right below;
		for (size_t i = 0; i < AsteroidList.size(); i++)
		{
			Asteroid currentAsteroid = AsteroidList[i];
			if (currentAsteroid.X == startX && currentAsteroid.Y > startY)
			{
				if (currentAsteroid.IsSeenBy(startX, startY, AsteroidPositions))
				{
					destroyed.push_back(currentAsteroid);
					AsteroidPositions[currentAsteroid.Y].erase(find(AsteroidPositions[currentAsteroid.Y].begin(), AsteroidPositions[currentAsteroid.Y].end(), currentAsteroid.X));
					AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), currentAsteroid));
					break;
				}
			}
		}

		maxSin = -1;
		// pass lowerleft quadrant;
		while (1) {
			vector<int> targetIdx = { -1 };
			double maxsin2 = 0;
			for (size_t i = 0; i < AsteroidList.size(); i++)
			{
				Asteroid currentAsteroid = AsteroidList[i];
				if (currentAsteroid.X < startX&& currentAsteroid.Y > startY)
				{
					if (currentAsteroid.Sine <= maxsin2 && currentAsteroid.Sine > maxSin)
					{
						maxsin2 = currentAsteroid.Sine;
						if (targetIdx[0] == -1) {
							targetIdx[0] = i;
						}
						else
						{
							targetIdx.push_back(i);
						}
					}
				}
			}
			if (targetIdx[0] != -1)
			{
				while (1) {
					if (AsteroidList[targetIdx[0]].IsSeenBy(startX, startY, AsteroidPositions))
					{
						maxSin = AsteroidList[targetIdx[0]].Sine;
						destroyed.push_back(AsteroidList[targetIdx[0]]);
						AsteroidPositions[AsteroidList[targetIdx[0]].Y].erase(find(AsteroidPositions[AsteroidList[targetIdx[0]].Y].begin(), AsteroidPositions[AsteroidList[targetIdx[0]].Y].end(), AsteroidList[targetIdx[0]].X));
						AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), AsteroidList[targetIdx[0]]));
						break;
					}
					else
					{
						targetIdx.erase(targetIdx.begin());
					}
				}
			}
			else
			{
				break;
			}
		}

		//delete left beside;
		for (size_t i = 0; i < AsteroidList.size(); i++)
		{
			Asteroid currentAsteroid = AsteroidList[i];
			if (currentAsteroid.X < startX && currentAsteroid.Y == startY)
			{
				if (currentAsteroid.IsSeenBy(startX, startY, AsteroidPositions))
				{
					destroyed.push_back(currentAsteroid);
					AsteroidPositions[currentAsteroid.Y].erase(find(AsteroidPositions[currentAsteroid.Y].begin(), AsteroidPositions[currentAsteroid.Y].end(), currentAsteroid.X));
					AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), currentAsteroid));
					break;
				}
			}
		}

		maxCos = 1;
		// pass upperleft quadrant;
		while (1) {
			vector<int> targetIdx = { -1 };
			double maxcos2 = 0;
			for (size_t i = 0; i < AsteroidList.size(); i++)
			{
				Asteroid currentAsteroid = AsteroidList[i];
				if (currentAsteroid.X < startX&& currentAsteroid.Y < startY)
				{
					if (currentAsteroid.Cosine >= maxcos2 && currentAsteroid.Cosine < maxCos)
					{
						maxcos2 = currentAsteroid.Cosine;
						if (targetIdx[0] == -1) {
							targetIdx[0] = i;
						}
						else
						{
							targetIdx.push_back(i);
						}
					}
				}
			}
			if (targetIdx[0] != -1)
			{
				while (1) {
					if (AsteroidList[targetIdx[0]].IsSeenBy(startX, startY, AsteroidPositions))
					{
						maxCos = AsteroidList[targetIdx[0]].Cosine;
						destroyed.push_back(AsteroidList[targetIdx[0]]);
						AsteroidPositions[AsteroidList[targetIdx[0]].Y].erase(find(AsteroidPositions[AsteroidList[targetIdx[0]].Y].begin(), AsteroidPositions[AsteroidList[targetIdx[0]].Y].end(), AsteroidList[targetIdx[0]].X));
						AsteroidList.erase(find(AsteroidList.begin(), AsteroidList.end(), AsteroidList[targetIdx[0]]));
						break;
					}
					else
					{
						targetIdx.erase(targetIdx.begin());
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	return destroyed;
}