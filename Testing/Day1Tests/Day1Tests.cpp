#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../../AdventOfCodeLib/Parsing.h"
#include "../../AdventOfCodeLib/Calculating.h"

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
