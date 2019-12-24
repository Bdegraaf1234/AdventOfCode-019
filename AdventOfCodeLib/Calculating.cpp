#include "Calculating.h"
#include <math.h>

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

int Calculating::CalculateTotalFuelRequirementIncludingFuel(vector<int> weightVect) {
	int req = 0;
	for (size_t i = 0; i < weightVect.size(); i++)
	{
		req += CalculateModuleFuelRequirementIncludingFuel(weightVect[i]);
	}
	return req;
}

