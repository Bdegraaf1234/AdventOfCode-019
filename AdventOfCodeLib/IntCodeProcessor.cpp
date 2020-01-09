#include "Instruction.h"

#include <string>
#include <fstream>
#include <iterator>
#include <iostream>

IntCodeProcessor::IntCodeProcessor(string path) {
	Memory = Parsing::ParseIntCodeProgram(path);
	Pointer = 0;
	RelativeBase = 0;
	while (Memory.size() < 1000000)
	{
		Memory.push_back(0);
	}
	OutPath = path.replace(path.end() - 4, path.end(), "_output.txt");
}

long long IntCodeProcessor::RunMultiProcessor(long long input, vector<int> inputPhase, vector<IntCodeProcessor> processors)
{
	if (processors.size() != inputPhase.size())
	{
		std::cout << "no phase input received for all processors";
	}
	IntCodeProcessor currentCpu;
	long long round = 0;
	while (1)
	{
		for (size_t i = 0; i < processors.size(); i++)
		{
			long long currentPhase = inputPhase[i];
			IntCodeProcessor currentCpu = processors[i];
			vector<long long> inputVect = { currentPhase, input };
			if (round == 0)
			{
				input = processors[i].RunUntilFirstOutputForceInput(inputVect);
			}
			else
			{
				input = processors[i].RunUntilFirstOutputForceInput(input);
				if (input == -1337)
				{
					break;
				}
			}
		}
		round++;				
		if (input == -1337)
		{
			break;
		}
	}
	return processors[4].Output;
}

long long IntCodeProcessor::Run(long long input)
{
	long long prevout = input;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);
		prevout = instruction.Execute(Memory, Pointer, RelativeBase, OutPath);
	}
	Output = prevout;
	return prevout;
}

long long IntCodeProcessor::RunForceInput(long long input)
{
	int prevoutIdx = 0;
	long long prevout = input;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);
		if (instruction.Identifier == 3 && prevoutIdx < 1)
		{
			instruction.Input = input;
			prevoutIdx++;
		}
		prevout = instruction.Execute(Memory, Pointer, RelativeBase, OutPath);
	}
	Output = prevout;
	return prevout;
}

long long IntCodeProcessor::Run(vector<long long> input)
{
	long long idx = 0;
	long long prevout = input[0];
	long long prevoutIdx = 0;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);
		if (instruction.Identifier == 3 && prevoutIdx < input.size())
		{
			instruction.Input = input[prevoutIdx];
			prevoutIdx++;
		}
		prevout = instruction.Execute(Memory, Pointer, RelativeBase, OutPath);
	}
	Output = prevout;
	return prevout;
}

//uses the input in the first found input long longruction
long long IntCodeProcessor::RunUntilFirstOutputForceInput(long long input)
{
	long long prevout = input;
	long long prevoutIdx = 0;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);		
		if (instruction.Identifier == 3 && prevoutIdx < 1)
		{
			instruction.Input = input;
			prevoutIdx++;
		}
		prevout = instruction.Execute(Memory, Pointer, RelativeBase, OutPath);
		if (instruction.Identifier == 4)
		{
			Output = prevout;
			return prevout;
		}
	}
	Output = prevout;
	return -1337;
}

//uses the input in the first found input long longruction
long long IntCodeProcessor::RunUntilFirstOutputForceInput(vector<long long> input)
{
	long long prevout = input[0];
	long long prevoutIdx = 0;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);
		if (instruction.Identifier == 3 && prevoutIdx < input.size())
		{
			instruction.Input = input[prevoutIdx];
			prevoutIdx++;
		}
		prevout = instruction.Execute(Memory, Pointer, RelativeBase, OutPath);
		if (instruction.Identifier == 4)
		{
			Output = prevout;
			return prevout;
		}
	}
	Output = prevout;
	return -1337;
}

long long IntCodeProcessor::ReverseEngineer(long long desiredOutcome)
{
	long long outcome = -1;
	vector<long long> startMem = Memory;
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			Memory = startMem;
			Memory[1] = i;
			Memory[2] = j;
			Run(-1);
			if (Memory[0] == desiredOutcome)
			{
				break;
			}
		}
		if (Memory[0] == desiredOutcome)
		{
			break;
		}
	}		
	if (Memory[0] == desiredOutcome)
	{
		outcome = (100 * Memory[1] + Memory[2]);
	}
	return outcome;
}

void IntCodeProcessor::WriteMemory(string path)
{
	std::ofstream output_file(path);
	std::ostream_iterator<long long> output_iterator(output_file, ",");
	std::copy(Memory.begin(), Memory.end(), output_iterator);
}
