#include "pch.h"
#include "pch.h"
#include "CppUnitTest.h"
#include <string>

#include "CppUnitTest.h"
#include "../../AdventOfCodeLib/IntCodeProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntCodeTests
{
	TEST_CLASS(IntCodeTests)
	{
	public:

		TEST_METHOD(ParseIntCode)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\Input\\input.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(157, (int)cpu.Memory.size());
		}

		TEST_METHOD(OpCode1Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode1.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run();
			Assert::AreEqual(2, cpu.Memory[0]);
		}

		TEST_METHOD(OpCode2Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode2.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run();
			Assert::AreEqual(6, cpu.Memory[3]);
		}

		TEST_METHOD(IntCodeTest)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\intCode.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run();
			Assert::AreEqual(30, cpu.Memory[0]);
		}

		TEST_METHOD(IntCode2Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\intCode2.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run();
			Assert::AreEqual(3500, cpu.Memory[0]);
		}

		TEST_METHOD(IntCodeRevEngineer)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\Input\\input.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			int res = cpu.ReverseEngineer(19690720);
			Assert::AreEqual(7603, res);
		}
	};
}
