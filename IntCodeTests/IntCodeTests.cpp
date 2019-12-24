#include "pch.h"
#include "pch.h"
#include "CppUnitTest.h"
#include "..\AdventOfCodeLib\Parsing.h"
#include "..\AdventOfCodeLib\IntCodeProcessing.h"
#include <string>

#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntCodeTests
{
	TEST_CLASS(IntCodeTests)
	{
	public:

		TEST_METHOD(ParseIntCode)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\Input\\input.txt";
			vector<int> intCode = Parsing::ParseIntCodeProgram(inFile);
			Assert::AreEqual(157, (int)intCode.size());
		}

		TEST_METHOD(OpCode1Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode1.txt";
			vector<int> intCode = Parsing::ParseIntCodeProgram(inFile);
			vector<int> res = IntCodeProcessing::Run(intCode);
			Assert::AreEqual(2, res[0]);
		}

		TEST_METHOD(OpCode2Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode2.txt";
			vector<int> intCode = Parsing::ParseIntCodeProgram(inFile);
			vector<int> res = IntCodeProcessing::Run(intCode);
			Assert::AreEqual(6, res[3]);
		}

		TEST_METHOD(IntCodeTest)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\intCode.txt";
			vector<int> intCode = Parsing::ParseIntCodeProgram(inFile);
			vector<int> res = IntCodeProcessing::Run(intCode);
			Assert::AreEqual(30, res[0]);
		}

		TEST_METHOD(IntCode2Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\intCode2.txt";
			vector<int> intCode = Parsing::ParseIntCodeProgram(inFile);
			vector<int> res = IntCodeProcessing::Run(intCode);
			Assert::AreEqual(3500, res[0]);
		}
	};
}
