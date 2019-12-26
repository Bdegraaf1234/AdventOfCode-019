#include "pch.h"
#include "CppUnitTest.h"

#include "../AdventOfCodeLib/Parsing.h"
#include "../AdventOfCodeLib/ElectricalGrid.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Day3Tests
{
	TEST_CLASS(Day3Tests)
	{
	public:

		TEST_METHOD(ParseinputTest)
		{
			vector<vector<string>> input = Parsing::ParseInputDay3("../../Day3/Input/input.txt");
			Assert::AreEqual((int)input[1].size(), 301);
		}

		TEST_METHOD(initializeEgrid)
		{
			ElectricalGrid grid = ElectricalGrid("../../Day3/Input/input.txt");
		}

		TEST_METHOD(GetOverlaps)
		{
			vector<vector<string>> input = Parsing::ParseInputDay3("../../Day3/Input/input.txt");
			Wire wireA = Wire();
			wireA.SetPath(input[0]);
			Wire wireB = Wire();
			wireB.SetPath(input[1]);

			map<int, vector<int>> overlapsA = wireA.GetOverlapMap(wireB);
		}

		TEST_METHOD(GetShortestDistance)
		{
			ElectricalGrid grid = ElectricalGrid("../../Day3/Input/input.txt");
			int res = grid.GetShortestManhattanDistance();
		}

		TEST_METHOD(GetLowestNumSteps)
		{
			ElectricalGrid grid = ElectricalGrid("../../Day3/Input/input.txt");
			int res = grid.GetLowestNumSteps();
		}
	};
}
