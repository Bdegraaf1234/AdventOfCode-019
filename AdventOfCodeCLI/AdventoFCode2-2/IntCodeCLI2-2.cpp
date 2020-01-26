// IntCodeCLI2-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include "../../AdventOfCodeLib/IntCodeProcessor.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

void main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "no arguments provided";
	}
	else
	{
		IntCodeProcessor cpu = IntCodeProcessor();
		vector<long long> startMem = Parsing::ParseIntCodeProgram(argv[1]);
		for (size_t i = 0; i < 100; i++)
		{
			for (size_t j = 0; j < 100; j++)
			{
				cpu.Memory = startMem;
				cpu.Memory[1] = i;
				cpu.Memory[2] = j;
				cpu.Run(0);
				if (cpu.Memory[0] == 19690720)
				{
					break;
				}
			}
			if (cpu.Memory[0] == 19690720)
			{
				break;
			}
		}
		cout << (100 * cpu.Memory[1] + cpu.Memory[2]);
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
