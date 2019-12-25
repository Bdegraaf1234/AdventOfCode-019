#include "IntCodeProcessor.h"
class Instruction {
public:
	Instruction(IntCodeProcessor& cpu, int pointer) {
		Cpu = cpu;
		Pointer = pointer;
		Identifier = Cpu.Memory[Pointer];

		if (Identifier == 1 || Identifier == 2)
		{
			NumParameters = 4;
		}
	}
	Instruction();
	IntCodeProcessor Cpu;
	int Pointer;
	int NumParameters;
	int Identifier;
	void Execute();
};