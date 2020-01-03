#include "Parsing.h"
#include "strtk.hpp"

#include <string>
#include <fstream>
#include <iostream>
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

vector<ImageLayer> Parsing::ParseInputDay8(string path, int width, int height) {
	string inString;
	vector<int> outVect;
	vector<ImageLayer> outLayers;
	string line;
	ifstream myfile(path);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			inString = line;
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
	}

	for (size_t i = 0; i < inString.size(); i++)
	{
		int j = inString[i];
		outVect.push_back(j - 48);
	}

	int contentSize = width * height;

	for (size_t i = 0; i < outVect.size(); i += contentSize)
	{
		vector<int> currentContent(150);
		std::copy(outVect.begin() + i, outVect.begin() + i + 150, currentContent.begin());
		ImageLayer layer = ImageLayer(height, width, currentContent);
		outLayers.push_back(layer);
	}

	return outLayers;
}

vector<vector<string>> Parsing::ParseInputDay3(string path)
{
	vector<vector<string>> outVect;

	string line;
	ifstream myfile(path);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			vector<string> currentVect;
			strtk::parse(line, ",", currentVect);
			outVect.push_back(currentVect);
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	return outVect;
}

vector<long long> Parsing::ParseIntCodeProgram(string path) {
	std::vector<long long> intList;
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

vector<string> Parsing::ParseInputDay6(string path)
{
	std::vector<string> orbitList;
	string line;
	ifstream myfile(path);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			strtk::parse(line, ",", orbitList);
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
	}

	return orbitList;
}
