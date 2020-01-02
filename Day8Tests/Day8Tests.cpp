#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../AdventOfCodeLib/Parsing.h"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Day8Tests
{
	TEST_CLASS(Day8Tests)
	{
	public:

		TEST_METHOD(findLeastZeroes)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day8\\Input\\input.txt";
			vector<ImageLayer> outVect = Parsing::ParseInputDay8(inFile, 25, 6);
			int minZeroCount = 6 * 25;
			int minZeroIdx = 0;
			vector<int> zeroCounts;
			for (size_t i = 0; i < outVect.size(); i++)
			{
				int zeroCount = 0;
				for (size_t j = 0; j < outVect[i].Content.size(); j++)
				{
					if (outVect[i].Content[j] == 0)
					{
						zeroCount++;
					}
				}
				zeroCounts.push_back(zeroCount);
				if (zeroCount < minZeroCount)
				{
					minZeroCount = zeroCount;
					minZeroIdx = i;
				}
			}
			//sort(zeroCounts.begin(), zeroCounts.end());
			int numOnes = 0;
			int numTwos = 0;
			for (size_t i = 0; i < outVect[minZeroIdx].Content.size(); i++)
			{
				if (outVect[minZeroIdx].Content[i] == 1)
				{
					numOnes++;
				}
				if (outVect[minZeroIdx].Content[i] == 2)
				{
					numTwos++;
				}
			}
			int result = numOnes * numTwos;
		}

		TEST_METHOD(Decode)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day8\\Input\\input.txt";
			vector<ImageLayer> outVect = Parsing::ParseInputDay8(inFile, 25, 6);
			ImageLayer res = ImageLayer::Decode(outVect);
			res.Print("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day8\\output\\output.txt");
		}
	};
}
