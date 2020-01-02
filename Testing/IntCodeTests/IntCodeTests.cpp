#include "pch.h"
#include "pch.h"
#include "CppUnitTest.h"
#include <string>

#include "CppUnitTest.h"
#include "../../AdventOfCodeLib/Instruction.h"
#include <algorithm>
#include <iostream>

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

		TEST_METHOD(RunIntegrationtestDay7)
		{
			std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day7\\TestInput\\Test1.txt";
			vector<int> input = { 4, 0 };
			IntCodeProcessor cpu = IntCodeProcessor(inFile);
			int ans = cpu.Run(input);
			cpu = IntCodeProcessor(inFile);
			input = { 3 };
			input.push_back(ans);
			ans = cpu.Run(input);
			cpu = IntCodeProcessor(inFile);
			input = { 2 };
			input.push_back(ans);
			ans = cpu.Run(input);
			cpu = IntCodeProcessor(inFile);
			input = { 1 };
			input.push_back(ans);
			ans = cpu.Run(input);
			cpu = IntCodeProcessor(inFile);
			input = { 0 };
			input.push_back(ans);
			ans = cpu.Run(input);
			Assert::AreEqual(ans, 43210);
		}

		TEST_METHOD(RunIntegrationtestDay7PartTwo)
		{
			int maxans = 0;
			vector<int> bestVect;
			//vector<int> PhaseInput = { 9, 8, 7, 6, 5 };
			vector<int> PhaseInput = { 5, 6, 7, 8, 9 };
			while (std::next_permutation(PhaseInput.begin(), PhaseInput.end()))
			{
				std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day7\\TestInput\\Test3.txt";
				IntCodeProcessor cpuA = IntCodeProcessor(inFile);
				IntCodeProcessor cpuB = IntCodeProcessor(inFile);
				IntCodeProcessor cpuC = IntCodeProcessor(inFile);
				IntCodeProcessor cpuD = IntCodeProcessor(inFile);
				IntCodeProcessor cpuE = IntCodeProcessor(inFile);
				vector<IntCodeProcessor> inVect = { cpuA, cpuB, cpuC, cpuD, cpuE };

				int ans = IntCodeProcessor::RunMultiProcessor(0, PhaseInput, inVect);

				if (ans > maxans)
				{
					maxans = ans;
					bestVect = PhaseInput;
				}
			};
			Assert::AreEqual(maxans, 139629729);
		}

		TEST_METHOD(RunIntegrationtestDay7PartTwoB)
		{
			int maxans = 0;
			vector<int> bestVect;
			//vector<int> PhaseInput = { 9, 8, 7, 6, 5 };
			vector<int> PhaseInput = { 5, 6, 7, 8, 9 };
			while (std::next_permutation(PhaseInput.begin(), PhaseInput.end()))
			{
				std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day7\\TestInput\\Test4.txt";
				IntCodeProcessor cpuA = IntCodeProcessor(inFile);
				IntCodeProcessor cpuB = IntCodeProcessor(inFile);
				IntCodeProcessor cpuC = IntCodeProcessor(inFile);
				IntCodeProcessor cpuD = IntCodeProcessor(inFile);
				IntCodeProcessor cpuE = IntCodeProcessor(inFile);
				vector<IntCodeProcessor> inVect = { cpuA, cpuB, cpuC, cpuD, cpuE };

				int ans = IntCodeProcessor::RunMultiProcessor(0, PhaseInput, inVect);

				if (ans > maxans)
				{
					maxans = ans;
					bestVect = PhaseInput;
				}
			};
			Assert::AreEqual(maxans, 18216);
		}

		TEST_METHOD(RealAnswerDay7PartTwo)
		{
			int maxans = 0;
			vector<int> bestVect;
			vector<int> PhaseInput = { 5, 6, 7, 8, 9 };
			while (std::next_permutation(PhaseInput.begin(), PhaseInput.end()))
			{
				std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day7\\Input\\input.txt";
				IntCodeProcessor cpuA = IntCodeProcessor(inFile);
				IntCodeProcessor cpuB = IntCodeProcessor(inFile);
				IntCodeProcessor cpuC = IntCodeProcessor(inFile);
				IntCodeProcessor cpuD = IntCodeProcessor(inFile);
				IntCodeProcessor cpuE = IntCodeProcessor(inFile);
				vector<IntCodeProcessor> inVect = { cpuA, cpuB, cpuC, cpuD, cpuE };

				int ans = IntCodeProcessor::RunMultiProcessor(0, PhaseInput, inVect);

				if (ans > maxans)
				{
					maxans = ans;
					bestVect = PhaseInput;
				}
			};
			Assert::AreEqual(maxans, 18216);
		}

		TEST_METHOD(Day7PartOne)
		{
			int maxans = 0;
			vector<int> bestVect;
			vector<int> PhaseInput = { 0, 1, 2, 3, 4 };
			while (std::next_permutation(PhaseInput.begin(), PhaseInput.end()))
			{
				std::string inFile = "C:\\Users\\Gebruiker\\source\\repos\\AdventOfCode\\Day7\\Input\\input.txt";
				vector<int> input = { PhaseInput[0], 0 };
				IntCodeProcessor cpu = IntCodeProcessor(inFile);
				int ans = cpu.Run(input);
				cpu = IntCodeProcessor(inFile);
				input = { PhaseInput[1], ans };
				ans = cpu.Run(input);
				cpu = IntCodeProcessor(inFile);
				input = { PhaseInput[2], ans };
				ans = cpu.Run(input);
				cpu = IntCodeProcessor(inFile);
				input = { PhaseInput[3], ans };
				ans = cpu.Run(input);
				cpu = IntCodeProcessor(inFile);
				input = { PhaseInput[4], ans };
				ans = cpu.Run(input);

				if (ans > maxans)
				{
					maxans = ans;
					bestVect = PhaseInput;
				}
			};
		}
	};
}
