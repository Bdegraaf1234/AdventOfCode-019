#include "Instruction.h"
#include <iostream>

Instruction::Instruction(int opcode, int pointer)
{
	Pointer = pointer;
	int size = CountNumbers(opcode);
	Identifier = opcode % 10;

	int minOpCode = opcode / 10;
	if (opcode % 100 < 10)
	{
		minOpCode /= 10;
	}

	int numParameters = 0;
	if (Identifier == 1 || Identifier == 2)
	{
		numParameters = 3;
	}
	else if (Identifier == 3 || Identifier == 4)
	{
		numParameters = 1;
	}
	for (size_t i = 0; i < numParameters; i++)
	{
		Parameters.push_back(Parameter());
	}
	int numPositionParam = CountNumbers(minOpCode);
	for (int i = numParameters - 1; i >= numPositionParam; i--)
	{
		Parameters[i].Mode = 0;
	}
	for (int i = 0; i < numPositionParam; i++)
	{
		Parameters[i].Mode = minOpCode % 10;
		minOpCode /= 10;
	}
}


int Instruction::Execute(vector<int>& memory, int& pointer)
{
	int result = -1;
	for (size_t i = 0; i < Parameters.size(); i++)
	{
		Parameters[i].Value = memory[pointer + 1 + i];
		Parameters[i].Resolve(memory);
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
	if (Identifier == 3)
	{
		result = memory[Parameters[0].ResolvedValue];
		std::cout << result;
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