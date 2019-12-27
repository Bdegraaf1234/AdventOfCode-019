#include "strtk.hpp"
#include "OrbitMap.h"

OrbitMap::OrbitMap(vector<string> input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		string currentInput = input[i];
		vector<string> ids;
		strtk::parse(currentInput, ")", ids);
		OrbitingObject orbiter(ids[1]);
		orbiter.OrbitalCenter = ids[0];
		orbiter.Distance = -1;
		orbiter.ConnectedObjects.push_back(ids[0]);
		ObjectsInOrbit.push_back(orbiter);
		auto og = find(ObjectsInOrbit.begin(), ObjectsInOrbit.end(), OrbitingObject(ids[0]));
		if (og != ObjectsInOrbit.end())
		{
			(*og).ConnectedObjects.push_back(ids[1]);
		}
		else if (ids[0] == "COM")
		{
			OrbitingObject n = OrbitingObject(ids[0]);
			n.ConnectedObjects.push_back(ids[1]);
			ObjectsInOrbit.push_back(n);
		}
	}
}

int OrbitMap::CountOrbits(OrbitingObject start)
{
	int numOrbits = 1;
	auto currentOrbit = find(ObjectsInOrbit.begin(), ObjectsInOrbit.end(), start.OrbitalCenter);
	while (currentOrbit != ObjectsInOrbit.end()) {
		currentOrbit = find(ObjectsInOrbit.begin(), ObjectsInOrbit.end(), OrbitingObject((*currentOrbit).OrbitalCenter));
		numOrbits++;
	}
	return numOrbits;
}

void OrbitMap::CalculateDistanceToObjects(OrbitingObject start)
{
	vector<OrbitingObject> unseenList = ObjectsInOrbit;
	vector<OrbitingObject> seenList;
	vector<OrbitingObject> potentList;
	auto foundstart = find(unseenList.begin(), unseenList.end(), start);
	(*foundstart).Distance = 0;
	seenList.push_back(start);
	potentList.push_back(start);
	unseenList.erase(foundstart);

	while (!unseenList.empty())
	{
		for (size_t i = 0; i < potentList.size(); i++)
		{
			int mindistance = -1;
			string hitString = "";
			int numSeenConnections = 0;
			for (size_t j = 0; j < potentList[i].ConnectedObjects.size(); j++)
			{
				auto found = find(seenList.begin(), seenList.end(), OrbitingObject(potentList[i].ConnectedObjects[j]));
				if (found == seenList.end())
				{
					auto unseenFound = find(unseenList.begin(), unseenList.end(), OrbitingObject(potentList[i].ConnectedObjects[j]));
					if ((mindistance == -1 && unseenFound != unseenList.end()) || mindistance > seenList[i].Distance + 1)
					{
						mindistance = potentList[i].Distance + 1;
						hitString = potentList[i].ConnectedObjects[j];
					}
				}
				else {
					numSeenConnections++;
				}
			}
			if (mindistance != -1)
			{
				auto unseenFound = find(unseenList.begin(), unseenList.end(), OrbitingObject(hitString));
				(*unseenFound).Distance = mindistance;
				seenList.push_back((*unseenFound));
				potentList.push_back((*unseenFound));
				unseenList.erase(find(unseenList.begin(), unseenList.end(), (*unseenFound)));
			}
			if (numSeenConnections == potentList[i].ConnectedObjects.size())
			{
				potentList.erase(find(potentList.begin(), potentList.end(), OrbitingObject(potentList[i].Id)));
			}
		}
		if (potentList.size() == 0)
		{
			for (size_t i = 0; i < unseenList.size(); i++)
			{
				int mindistance = -1;
				for (size_t j = 0; j < unseenList[i].ConnectedObjects.size(); j++)
				{
					auto found = find(seenList.begin(), seenList.end(), OrbitingObject(unseenList[i].ConnectedObjects[j]));
					if (found != seenList.end())
					{
						if (mindistance == -1 || mindistance > (*found).Distance)
						{
							mindistance = (*found).Distance + 1;
						}
					}
				}
				if (mindistance != -1)
				{
					unseenList[i].Distance = mindistance;
					seenList.push_back(unseenList[i]);
					potentList.push_back(unseenList[i]);
					unseenList.erase(find(unseenList.begin(), unseenList.end(), unseenList[i]));
				}
			}
		}
	}
	ObjectsInOrbit = seenList;
}