#include "pch.h"
#include "CppUnitTest.h"
#include "../AdventOfCodeLib/OrbitMap.h"
#include "../AdventOfCodeLib/Parsing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Day6Tests
{
	TEST_CLASS(Day6Tests)
	{
	public:

		TEST_METHOD(InitializeOrbitmap)
		{
			vector<string> inputList = Parsing::ParseInputDay6("../../Day6/TestInput/testinput.txt");
			OrbitMap testMap = OrbitMap(inputList);
		}

		TEST_METHOD(CountOrbits)
		{
			vector<string> inputList = Parsing::ParseInputDay6("../../Day6/TestInput/testinput.txt");
			OrbitMap testMap = OrbitMap(inputList);
			int orbitCount = 0;
			for (size_t i = 0; i < testMap.ObjectsInOrbit.size(); i++)
			{
				orbitCount += testMap.CountOrbits(testMap.ObjectsInOrbit[i]);
			}
			Assert::AreEqual(42, orbitCount);
		}

		TEST_METHOD(Distances)
		{
			vector<string> inputList = Parsing::ParseInputDay6("../../Day6/TestInput/testinput.txt");
			OrbitMap testMap = OrbitMap(inputList);
			for (size_t i = 9; i < testMap.ObjectsInOrbit.size(); i++)
			{
				testMap.CalculateDistanceToObjects(testMap.ObjectsInOrbit[i]);
			}
		}

		TEST_METHOD(InitializeRealOrbitmap)
		{
			vector<string> inputList = Parsing::ParseInputDay6("../../Day6/Input/input.txt");
			OrbitMap testMap = OrbitMap(inputList);
		}

		TEST_METHOD(OrbitalCountRealOrbitmap)
		{
			vector<string> inputList = Parsing::ParseInputDay6("../../Day6/Input/input.txt");
			OrbitMap testMap = OrbitMap(inputList);
			int orbitCount = 0;
			for (size_t i = 0; i < testMap.ObjectsInOrbit.size(); i++)
			{
				orbitCount += testMap.CountOrbits(testMap.ObjectsInOrbit[i]);
			}
			Assert::AreEqual(42, orbitCount);
		}

		TEST_METHOD(DistancesRealOrbitmap)
		{
			vector<string> inputList = Parsing::ParseInputDay6("../../Day6/Input/input.txt");
			OrbitMap testMap = OrbitMap(inputList);
			testMap.CalculateDistanceToObjects(*find(testMap.ObjectsInOrbit.begin(), testMap.ObjectsInOrbit.end(), OrbitingObject("SAN")));
			auto santa = *find(testMap.ObjectsInOrbit.begin(), testMap.ObjectsInOrbit.end(), OrbitingObject("YOU"));
			Assert::AreEqual(santa.Distance, 1337);
		}
	};
}
