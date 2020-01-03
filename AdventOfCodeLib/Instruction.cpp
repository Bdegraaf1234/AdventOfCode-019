#include "Instruction.h"
#include <iostream>
#include <fstream>



Instruction::Instruction(int opcode, int pointer, long long input)
{
	// save the pointer
	Pointer = pointer;

	Identifier = opcode % 10;
	Input = input;

	// check if the opcode is 0X or just a single number (X)
	int minOpCode = opcode / 10;
	if (opcode % 100 < 10)
	{
		minOpCode /= 10;
	}

	int numParameters;
	if (Identifier == 1 || Identifier == 2 || Identifier == 7 || Identifier == 8)
	{
		numParameters = 3;
	}
	else if (Identifier == 3 || Identifier == 4 || Identifier == 9)
	{
		numParameters = 1;
	}
	else if (Identifier == 5 || Identifier == 6)
	{
		numParameters = 2;
	}
	else
	{
		throw new exception("unrecognized opcode");
	}

	//initialize the parameters
	for (size_t i = 0; i < numParameters; i++)
	{
		Parameters.push_back(Parameter());
	}

	int numPositionParam = CountNumbers(minOpCode);

	//Set the mode for the leading zeroes
	for (int i = numParameters - 1; i >= numPositionParam; i--)
	{
		Parameters[i].Mode = 0;
	}
	//parse the mode for the given parametermodes
	for (int i = 0; i < numPositionParam; i++)
	{
		Parameters[i].Mode = minOpCode % 10;
		minOpCode /= 10;
	}
}


long long Instruction::Execute(vector<long long>& memory, int& pointer, int& relativeBase, string outPath)
{
	long long result = -1ll;
	for (size_t i = 0; i < Parameters.size(); i++)
	{
		Parameters[i].Value = memory[pointer + 1 + i];
		Parameters[i].Resolve(memory, relativeBase);
	}
	if (Identifier == 1)
	{
		memory[Parameters[2].Value] = Parameters[0].ResolvedValue + Parameters[1].ResolvedValue;
	}
	if (Identifier == 2)
	{
		memory[Parameters[2].Value] = Parameters[0].ResolvedValue * Parameters[1].ResolvedValue;
	}
	if (Identifier == 3)
	{
		memory[Parameters[0].Value] = Input;
	}
	if (Identifier == 4)
	{
		ofstream myfile;
		myfile.open(outPath, std::ios::app);
		result = Parameters[0].ResolvedValue;
		myfile << result;
		myfile << ',';
		myfile.close();
		std::cout << result;
		pointer += Parameters.size() + 1;
		return result;
	}
	if (Identifier == 5)
	{
		if (Parameters[0].ResolvedValue != 0)
		{
			pointer = Parameters[1].ResolvedValue;
			return result;
		}
	}
	if (Identifier == 6)
	{
		if (Parameters[0].ResolvedValue == 0)
		{
			pointer = Parameters[1].ResolvedValue;
			return result;
		}
	}
	if (Identifier == 7)
	{
		int res;
		if (Parameters[0].ResolvedValue < Parameters[1].ResolvedValue)
		{
			res = 1;
		}
		else
		{
			res = 0;
		}
		memory[Parameters[2].Value] = res;
	}
	if (Identifier == 8)
	{
		int res;
		if (Parameters[0].ResolvedValue == Parameters[1].ResolvedValue)
		{
			res = 1;
		}
		else
		{
			res = 0;
		}
		memory[Parameters[2].Value] = res;
	}
	if (Identifier == 9)
	{
		relativeBase += Parameters[0].ResolvedValue;
	}
	pointer += Parameters.size() + 1;
	return result;
}

int Instruction::CountNumbers(int num) {
	int count = 0;
	while (num != 0) {
		count++;
		num /= 10;
	}
	return count;
}