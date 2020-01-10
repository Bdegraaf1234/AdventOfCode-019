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

			Assert::AreEqual((long long)space.GetPeriod(), 2772ll);
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
			Assert::AreEqual(9127, ans);
		}

		TEST_METHOD(RunPart2)
		{
			Space space = Space();
			space.Moons = Parsing::ParseInputDay12("C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day12\\Input\\input.txt");

			Assert::AreEqual((long long)space.GetPeriod(), 176810283017562ll);
		}
	};
}
