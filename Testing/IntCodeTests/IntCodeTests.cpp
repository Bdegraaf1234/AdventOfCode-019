#include "pch.h"
#include "pch.h"
#include "CppUnitTest.h"
#include <string>

#include "CppUnitTest.h"
#include "../../AdventOfCodeLib/Instruction.h"

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

		TEST_METHOD(ParseInstruction1)
		{
			Instruction instruction = Instruction(1002, 1);
			Assert::AreEqual((int)instruction.Parameters.size(), 3);
			Assert::AreEqual((int)instruction.Parameters[0].Mode, 0);
			Assert::AreEqual((int)instruction.Parameters[1].Mode, 1);
			Assert::AreEqual((int)instruction.Parameters[2].Mode, 0);
		}

		TEST_METHOD(ParseInstruction2)
		{
			Instruction	instruction = Instruction(11001, 1);
			Assert::AreEqual((int)instruction.Parameters.size(), 3);
			Assert::AreEqual((int)instruction.Parameters[0].Mode, 0);
			Assert::AreEqual((int)instruction.Parameters[1].Mode, 1);
			Assert::AreEqual((int)instruction.Parameters[2].Mode, 1);
		}

		TEST_METHOD(ParseInstruction3)
		{
			Instruction instruction = Instruction(3, 1);
			Assert::AreEqual((int)instruction.Parameters.size(), 1);
			Assert::AreEqual((int)instruction.Parameters[0].Mode, 0);
		}

		TEST_METHOD(ParseInstruction4)
		{
			Instruction instruction = Instruction(14, 1);
			Assert::AreEqual((int)instruction.Parameters.size(), 1);
			Assert::AreEqual((int)instruction.Parameters[0].Mode, 1);
		}
	};
}
