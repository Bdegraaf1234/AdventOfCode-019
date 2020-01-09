#include "pch.h"
#include "CppUnitTest.h"
#include "../AdventOfCodeLib/Parsing.h"
#include "../AdventOfCodeLib/Space.h"
#include "../AdventOfCodeLib/Calculating.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Day12Tests
{
	TEST_CLASS(Day12Tests)
	{
	public:

		TEST_METHOD(Test)
		{
			Space space = Space();
			space.Moons = Parsing::ParseInputDay12("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day12\\TestInput\\testInput.txt");
			for (size_t i = 0; i < 10; i++)
			{
				space.AdvanceTime({ 0, 1, 2 });
			}
			int ans = space.GetTotalEnergy();
			Assert::AreEqual(ans, 179);
		}


		TEST_METHOD(TestPart2)
		{
			Space space = Space();
			space.Moons = Parsing::ParseInputDay12("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day12\\TestInput\\testInput.txt");
			vector<Moon> startState = Parsing::ParseInputDay12("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day12\\TestInput\\testInput.txt");
			space.AdvanceTime({ 0, 1, 2 });
			while (startState != space.Moons)
			{
				space.AdvanceTime({ 0, 1, 2 });
			}
			long long ans = space.Time;
			Assert::AreEqual(ans, 2772ll);
		}


		TEST_METHOD(TestAltPart2)
		{
			Space space = Space();
			space.Moons = Parsing::ParseInputDay12("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day12\\TestInput\\testInput.txt");
			vector<Moon> startState = Parsing::ParseInputDay12("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day12\\TestInput\\testInput.txt");
			vector<int> axes = { 0, 1, 2 };
			vector<long long> periods = vector<long long>();
			for (size_t j = 0; j < 4; j++)
			{
				for (size_t i = 0; i < axes.size(); i++)
				{
					periods.push_back((long long)space.GetPeriod(i, j));
				}
			}

			Assert::AreEqual(Calculating::calculateLeastCommonMultiple(periods), 2772ll);
		}

		TEST_METHOD(RunPart1)
		{
			Space space = Space();
			space.Moons = Parsing::ParseInputDay12("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day12\\Input\\input.txt");
			for (size_t i = 0; i < 1000; i++)
			{
				space.AdvanceTime({ 0, 1, 2 });
			}
			int ans = space.GetTotalEnergy();
		}

		TEST_METHOD(RunPart2)
		{
			Space space = Space();
			space.Moons = Parsing::ParseInputDay12("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day12\\Input\\input.txt");
			space.AdvanceTime({ 0, 1, 2 });
			vector<int> axes = { 0, 1, 2 };
			vector<long long> periods = vector<long long>();
			for (size_t j = 0; j < 4; j++)
			{
				for (size_t i = 0; i < axes.size(); i++)
				{
					periods.push_back((long long)space.GetPeriod(i, j));
				}
			}

			Assert::AreEqual(Calculating::calculateLeastCommonMultiple(periods), 2772ll);
		}
	};
}
