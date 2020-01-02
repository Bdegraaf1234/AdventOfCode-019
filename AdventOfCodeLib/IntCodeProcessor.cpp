#include "Instruction.h"

#include <string>
#include <fstream>
#include <iterator>
#include <iostream>

IntCodeProcessor::IntCodeProcessor(string path) {
	Memory = Parsing::ParseIntCodeProgram(path);
	Pointer = 0;
}

int IntCodeProcessor::RunMultiProcessor(int input, vector<int> inputPhase, vector<IntCodeProcessor> processors)
{
	if (processors.size() != inputPhase.size())
	{
		std::cout << "no phase input received for all processors";
	}
	IntCodeProcessor currentCpu;
	int round = 0;
	while (1)
	{
		for (size_t i = 0; i < processors.size(); i++)
		{
			int currentPhase = inputPhase[i];
			IntCodeProcessor currentCpu = processors[i];
			vector<int> inputVect = { currentPhase, input };
			if (round == 0)
			{
				input = processors[i].RunUntilFirstOutput(inputVect);
			}
			else
			{
				input = processors[i].RunUntilFirstOutput(input);
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

int IntCodeProcessor::Run(int input)
{
	int prevout = input;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);
		prevout = instruction.Execute(Memory, Pointer);
	}
	Output = prevout;
	return prevout;
}

int IntCodeProcessor::Run(vector<int> input)
{
	int idx = 0;
	int prevout = input[0];
	int prevoutIdx = 0;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);
		if (instruction.Identifier == 3 && prevoutIdx < input.size())
		{
			instruction.Input = input[prevoutIdx];
			prevoutIdx++;
		}
		prevout = instruction.Execute(Memory, Pointer);
	}
	Output = prevout;
	return prevout;
}

//uses the input in the first found input intruction
int IntCodeProcessor::RunUntilFirstOutput(int input)
{
	int prevout = input;
	int prevoutIdx = 0;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);		
		if (instruction.Identifier == 3 && prevoutIdx < 1)
		{
			instruction.Input = input;
			prevoutIdx++;
		}
		prevout = instruction.Execute(Memory, Pointer);
		if (instruction.Identifier == 4)
		{
			Output = prevout;
			return prevout;
		}
	}
	Output = prevout;
	return -1337;
}

//uses the input in the first found input intruction
int IntCodeProcessor::RunUntilFirstOutput(vector<int> input)
{
	int prevout = input[0];
	int prevoutIdx = 0;
	while (Memory[Pointer] != 99)
	{
		Instruction instruction = Instruction(Memory[Pointer], Pointer, prevout);
		if (instruction.Identifier == 3 && prevoutIdx < input.size())
		{
			instruction.Input = input[prevoutIdx];
			prevoutIdx++;
		}
		prevout = instruction.Execute(Memory, Pointer);
		if (instruction.Identifier == 4)
		{
//			Pointer = 0;
			Output = prevout;
			return prevout;
		}
	}
	Output = prevout;
	return -1337;
}

int IntCodeProcessor::ReverseEngineer(int desiredOutcome)
{
	int outcome = -1;
	vector<int> startMem = Memory;
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
	std::ostream_iterator<int> output_iterator(output_file, ",");
	std::copy(Memory.begin(), Memory.end(), output_iterator);
}
