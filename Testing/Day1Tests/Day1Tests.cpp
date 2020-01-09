#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../../AdventOfCodeLib/Parsing.h"
#include "../../AdventOfCodeLib/Calculating.h"
#include "../../AdventOfCodeLib/AsteroidBelt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Day1Tests
{
	TEST_CLASS(Day1Tests)
	{
	public:

		TEST_METHOD(CountLines)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day1\\Input\\input.txt";
			int numLines = Parsing::GetNumberOfLines(inFile);
			Assert::AreEqual(100, numLines);
		}

		TEST_METHOD(ParseInputDay1)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day1\\Input\\input.txt";
			vector<int> outVect = Parsing::ParseInputDay1(inFile);
			Assert::AreEqual(53854, outVect[99]);
		}

		TEST_METHOD(ParseInputDay6)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day6\\TestInput\\testInput.txt";
			vector<string> outVect = Parsing::ParseInputDay6(inFile);
			Assert::AreEqual((string) "B)C", outVect[1]);
		}

		TEST_METHOD(ParseInputDay8)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day8\\Input\\input.txt";
			vector<ImageLayer> outVect = Parsing::ParseInputDay8(inFile, 25, 6);
			Assert::AreEqual(2, outVect[2].Content[99]);
		}

		TEST_METHOD(ParseInputDay10)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day10\\Input\\input.txt";
			map<int, vector<int>> outVect = Parsing::ParseInputDay10(inFile);
			Assert::AreEqual(8, (int)outVect[0].size());
		}

		TEST_METHOD(initializeBeltDay10)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day10\\Input\\input.txt";
			map<int, vector<int>> outVect = Parsing::ParseInputDay10(inFile);
			AsteroidBelt belt = AsteroidBelt(outVect);
			Assert::AreEqual(363, (int)belt.AsteroidList.size());
		}

		TEST_METHOD(CalculateLCM)
		{
			long long res = Calculating::calculateLeastCommonMultiple({ 6ll, 28ll, 44ll, 18ll, 28ll, 44ll, 18ll, 28ll, 44ll, 6ll, 28ll, 44ll });
			Assert::AreEqual(2772ll, res);
		}

		TEST_METHOD(CalculateModuleFuel)
		{
			int req = Calculating::CalculateModuleFuelRequirement(12);
			Assert::AreEqual(2, req);
		}

		TEST_METHOD(CalculatetotalFuel)
		{
			std::vector<int> intVect;

			intVect.push_back(12);
			intVect.push_back(11);
			intVect.push_back(12234);
			intVect.push_back(1324232);
			int req = Calculating::CalculateTotalFuelRequirement(intVect);
			Assert::AreEqual(445487, req);
		}

		TEST_METHOD(CalculateModleFuelIncludingFuel)
		{
			int req = Calculating::CalculateModuleFuelRequirementIncludingFuel(100756);
			Assert::AreEqual(50346, req);
		}

		TEST_METHOD(CalculateTotalFuelIncludingFuel)
		{
			std::vector<int> intVect;

			intVect.push_back(12);
			intVect.push_back(11);
			intVect.push_back(12234);
			intVect.push_back(1324232);
			int req = Calculating::CalculateTotalFuelRequirementIncludingFuel(intVect);
			Assert::AreEqual(668170, req);
		}
	};
}
