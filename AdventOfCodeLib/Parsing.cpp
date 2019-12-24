#include "Parsing.h"
#include "strtk.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <vector>
using namespace::std;

int Parsing::GetNumberOfLines(string path) {
	string line;
	ifstream myfile(path);

	int outCount = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
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

vector<int> Parsing::ParseInputDay1(string path) {
	vector<int> outVect;

	string line;
	ifstream myfile(path);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			outVect.push_back(std::stoi(line));
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
	}

	return outVect;
}

vector<int> Parsing::ParseIntCodeProgram(string path) {
	std::vector<int> intList;
	string line;
	ifstream myfile(path);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			strtk::parse(line, ",", intList);
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
	}

	return intList;
}