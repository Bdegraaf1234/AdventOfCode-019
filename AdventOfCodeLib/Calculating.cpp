#include "Calculating.h"
#include <math.h>
#include <set>
#include <algorithm>

using namespace::std;

int Calculating::CalculateModuleFuelRequirement(int weight) {
	int divThree = floor(weight / 3);
	return divThree - 2;
}

int Calculating::CalculateTotalFuelRequirement(vector<int> weightVect) {
	int req = 0;
	for (size_t i = 0; i < weightVect.size(); i++)
	{
		req += CalculateModuleFuelRequirement(weightVect[i]);
	}
	return req;
}

int Calculating::CalculateModuleFuelRequirementIncludingFuel(int weight) {
	int newReq = CalculateModuleFuelRequirement(weight);
	int fuelReq = 0;
	while (newReq >= 0)
	{
		fuelReq += newReq;
		newReq = CalculateModuleFuelRequirement(newReq);
	}

	return fuelReq;
}

long long Calculating::calculateLeastCommonMultiple(vector<long long> input)
{
	long long i = 0;
	vector<long long> saveInput = input;
	while (std::set<int>(input.begin(), input.end()).size() > 1)
	{
		i++;
		vector<long long> toSort = input;
		std::sort(toSort.begin(), toSort.end());
		auto lowest = std::find(input.begin(), input.end(), toSort[0]);
		int index = std::distance(input.begin(), lowest);
		input[index] += saveInput[index];
	}
	return input[0] * 2;
}

int Calculating::CalculateTotalFuelRequirementIncludingFuel(vector<int> weightVect) {
	int req = 0;
	for (size_t i = 0; i < weightVect.size(); i++)
	{
		req += CalculateModuleFuelRequirementIncludingFuel(weightVect[i]);
	}
	return req;
}

