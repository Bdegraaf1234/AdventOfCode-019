#include "Parsers.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int GetNumberOfLines() {
	string line;
	ifstream myfile("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day1\\Input\\input.txt");

	int outCount = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
			outCount++;
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
	}

	return outCount;
}
