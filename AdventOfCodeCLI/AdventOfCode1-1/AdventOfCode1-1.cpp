// AdventOfCodeCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AdventOfCode1-1.h"
#include "../../AdventOfCodeLib/Parsing.h"
#include "../../AdventOfCodeLib/Calculating.h"
#include <string>

using namespace::std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "no arguments provided";
		return -1;
	}
	else
	{
		cout << argv[1] << "\n";
		std::vector<int> weightVect = Parsing::ParseInputDay1(argv[1]);
		int fuelReq = Calculating::CalculateTotalFuelRequirement(weightVect);
		cout << fuelReq << "\n";
		return fuelReq;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
