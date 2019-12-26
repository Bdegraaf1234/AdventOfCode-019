#include "Instruction.h"

#include <string>
#include <fstream>
#include <iterator>

IntCodeProcessor::IntCodeProcessor(string path) {
	Memory = Parsing::ParseIntCodeProgram(path);
}

void IntCodeProcessor::Run()
{
	int idx = 0;
	while (Memory[idx] != 99)
	{
		Instruction instruction = Instruction(Memory[idx], idx);
		int prevout = instruction.Execute(Memory, idx);
	}
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
			Run();
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

void IntCodeProcessor::ProcessOpCode1(std::vector<int>& intCode, int& idx)
{
	int idxA = intCode[idx + 1];
	int idxB = intCode[idx + 2];
	int idxRes = intCode[idx + 3];

	intCode[idxRes] = intCode[idxA] + intCode[idxB];
	idx += 4;
}

void IntCodeProcessor::ProcessOpCode2(std::vector<int>& intCode, int& idx)
{
	int idxA = intCode[idx + 1];
	int idxB = intCode[idx + 2];
	int idxRes = intCode[idx + 3];

	intCode[idxRes] = intCode[idxA] * intCode[idxB];
	idx += 4;
}

void IntCodeProcessor::ProcessOpCode3(std::vector<int>& intCode, int& idx, int& input)
{
	int idxRes = intCode[idx + 1];

	intCode[idxRes] = input;
	idx += 2;
}


int IntCodeProcessor::ProcessOpCode4(std::vector<int>& intCode, int& idx)
{
	int idxRes = intCode[idx + 1];

	idx += 2;
	return intCode[idxRes];
}
