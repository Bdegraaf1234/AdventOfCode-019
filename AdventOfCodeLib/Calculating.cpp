#include "Calculating.h"
#include <math.h>
#include <set>
#include <algorithm>
#include <numeric>

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

long long Calculating::calculateLeastCommonMultipleOld(vector<long long> input)
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
	return input[0];
}

long long Calculating::calculateLeastCommonMultiple(vector<long long> input)
{
	vector<long long> saveInput = input;

	vector<long long> toSort = input;
	int idx = 0;
	while (std::set<int>(input.begin(), input.end()).size() > 1)
	{
		if (toSort[0] > toSort[1])
		{
			std::sort(toSort.begin(), toSort.end());
			auto lowest = std::find(input.begin(), input.end(), toSort[0]);
			idx = std::distance(input.begin(), lowest);
		}
		toSort[0] += saveInput[idx];
		input[idx] += saveInput[idx];
	}
	return input[0];
}

long long gcd(long long a, long long b)
{
	for (;;)
	{
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

long long lcm(long long a, long long b)
{
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

long long Calculating::calculateLeastCommonMultipleNew(vector<long long> input)
{
	std::sort(input.begin(), input.end());
	long long arr[] = { input[0], input[1], input[2] };
	return std::accumulate(arr + 1, arr + 3, arr[0], lcm);
}

int Calculating::CalculateTotalFuelRequirementIncludingFuel(vector<int> weightVect) {
	int req = 0;
	for (size_t i = 0; i < weightVect.size(); i++)
	{
		req += CalculateModuleFuelRequirementIncludingFuel(weightVect[i]);
	}
	return req;
}

