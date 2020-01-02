// Day8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../AdventOfCodeLib/Parsing.h"

int main()
{
    std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day8\\Input\\input.txt";
	vector<ImageLayer> outVect = Parsing::ParseInputDay8(inFile, 25, 6);
	ImageLayer res = ImageLayer::Decode(outVect);
	res.Print("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day8\\output\\output.txt");
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
