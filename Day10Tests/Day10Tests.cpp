#include "pch.h"
#include "CppUnitTest.h"
#include <map>
#include <vector>
#include "../AdventOfCodeLib/Parsing.h"
#include "../AdventOfCodeLib/AsteroidBelt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Day10Tests
{
	TEST_CLASS(Day10Tests)
	{
	public:
		TEST_METHOD(bestAsteroid)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day10\\TestInput\\small.txt";
			map<int, vector<int>> outVect = Parsing::ParseInputDay10(inFile);
			AsteroidBelt belt = AsteroidBelt(outVect);
			Asteroid bestPos = belt.GetBestPosition();
			Assert::AreEqual(bestPos.Id, 8);
		}

		TEST_METHOD(destroyAsteroid)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day10\\TestInput\\small.txt";
			map<int, vector<int>> outVect = Parsing::ParseInputDay10(inFile);
			AsteroidBelt belt = AsteroidBelt(outVect);
			Asteroid bestPos = belt.GetBestPosition();
			vector<Asteroid> ans = belt.DestroyAll(bestPos);
		}

		TEST_METHOD(bestAsteroid2)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day10\\TestInput\\larger.txt";
			map<int, vector<int>> outVect = Parsing::ParseInputDay10(inFile);
			AsteroidBelt belt = AsteroidBelt(outVect);
			Asteroid bestPos = belt.GetBestPosition();
			Assert::AreEqual(bestPos.Id, 33);
		}

		TEST_METHOD(destroyAsteroid2)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day10\\TestInput\\unit2.txt";
			map<int, vector<int>> outVect = Parsing::ParseInputDay10(inFile);
			AsteroidBelt belt = AsteroidBelt(outVect);
			Asteroid bestPos = belt.GetBestPosition();
			vector<Asteroid> ans = belt.DestroyAll(bestPos);
		}

		TEST_METHOD(bestAsteroidReal)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day10\\Input\\input.txt";
			map<int, vector<int>> outVect = Parsing::ParseInputDay10(inFile);
			AsteroidBelt belt = AsteroidBelt(outVect);
			Asteroid bestPos = belt.GetBestPosition();
			Assert::AreEqual(bestPos.Id, 305);
		}

		TEST_METHOD(destroyAsteroidReal)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day10\\Input\\input.txt";
			map<int, vector<int>> outVect = Parsing::ParseInputDay10(inFile);
			AsteroidBelt belt = AsteroidBelt(outVect);
			Asteroid bestPos = belt.GetBestPosition();
			vector<Asteroid> ans = belt.DestroyAll(bestPos);
		}
	};
}
