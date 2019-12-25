#include "Instruction.h"

void Instruction::Execute() {
	if (Identifier = 1)
	{
		int idxA = Cpu.Memory[Pointer + 1];
		int idxB = Cpu.Memory[Pointer + 2];
		int idxRes = Cpu.Memory[Pointer + 3];

		Cpu.Memory[idxRes] = Cpu.Memory[idxA] + Cpu.Memory[idxB];
	}
	else if (Identifier == 2)
	{
		int idxA = Cpu.Memory[Pointer + 1];
		int idxB = Cpu.Memory[Pointer + 2];
		int idxRes = Cpu.Memory[Pointer + 3];

		Cpu.Memory[idxRes] = Cpu.Memory[idxA] * Cpu.Memory[idxB];
	}
}