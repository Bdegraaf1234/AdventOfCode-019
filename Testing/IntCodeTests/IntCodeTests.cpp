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

		TEST_METHOD(ParseIntCodeDay5)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day5\\Input\\input.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(678, (int)cpu.Memory.size());
		}

		TEST_METHOD(OpCode1Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode1.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run(-1);
			Assert::AreEqual(2, cpu.Memory[0]);
		}

		TEST_METHOD(OpCode2Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode2.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run(-1);
			Assert::AreEqual(6, cpu.Memory[3]);
		}

		TEST_METHOD(OpCode3and4Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode34.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run(1);
		}

		TEST_METHOD(OpCode56PosTestPos)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode56pos.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(cpu.Run(1), 1);
		}

		TEST_METHOD(OpCode56PosTestNeg)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode56pos.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(cpu.Run(0), 0);
		}

		TEST_METHOD(OpCode56ImmTestPos)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode56imm.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(cpu.Run(1), 1);
		}

		TEST_METHOD(OpCode56ImmTestNeg)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode56imm.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(cpu.Run(0), 0);
		}

		TEST_METHOD(OpCode78ImmTestPos)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode78imm.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(cpu.Run(8), 1);
		}

		TEST_METHOD(OpCode78ImmTestNeg)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode78imm.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(cpu.Run(0), 0);
		}

		TEST_METHOD(OpCode78PosTestPos)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode78pos.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(cpu.Run(8), 1);
		}

		TEST_METHOD(OpCode78PosTestNeg)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\opcode78pos.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			Assert::AreEqual(cpu.Run(0), 0);
		}

		TEST_METHOD(IntCodeTest)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\intCode.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run(-1);
			Assert::AreEqual(30, cpu.Memory[0]);
		}

		TEST_METHOD(IntCode2Test)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\intCode2.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run(-1);
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
			Instruction instruction = Instruction(1002, 1, -1);
			Assert::AreEqual((int)instruction.Parameters.size(), 3);
			Assert::AreEqual((int)instruction.Parameters[0].Mode, 0);
			Assert::AreEqual((int)instruction.Parameters[1].Mode, 1);
			Assert::AreEqual((int)instruction.Parameters[2].Mode, 0);
		}

		TEST_METHOD(ParseInstruction2)
		{
			Instruction	instruction = Instruction(11001, 1, -1);
			Assert::AreEqual((int)instruction.Parameters.size(), 3);
			Assert::AreEqual((int)instruction.Parameters[0].Mode, 0);
			Assert::AreEqual((int)instruction.Parameters[1].Mode, 1);
			Assert::AreEqual((int)instruction.Parameters[2].Mode, 1);
		}

		TEST_METHOD(ParseInstruction3)
		{
			Instruction instruction = Instruction(3, 1, -1);
			Assert::AreEqual((int)instruction.Parameters.size(), 1);
			Assert::AreEqual((int)instruction.Parameters[0].Mode, 0);
		}

		TEST_METHOD(ParseInstruction4)
		{
			Instruction instruction = Instruction(14, 1, -1);
			Assert::AreEqual((int)instruction.Parameters.size(), 1);
			Assert::AreEqual((int)instruction.Parameters[0].Mode, 1);
		}

		TEST_METHOD(RunIntCodeDay5)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day5\\Input\\input.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			cpu.Run(5);
		}

		TEST_METHOD(RunIntegrationtestDay5)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day2\\TestInput\\integration.txt";
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			int ans = cpu.Run(7);
		}
	};
}
