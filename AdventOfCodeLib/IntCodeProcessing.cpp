#include "IntCodeProcessing.h"

vector<int> IntCodeProcessing::Run(vector<int> intCode)
{
	int idx = 0;
	while (intCode[idx] != 99)
	{
		if (intCode[idx] == 1)
		{
			ProcessOpCode1(intCode, idx);
		}
		else
		{
			ProcessOpCode2(intCode, idx);
		};
	}
	return intCode;
}

void IntCodeProcessing::ProcessOpCode1(std::vector<int>& intCode, int& idx)
{
	int idxA = intCode[idx + 1];
	int idxB = intCode[idx + 2];
	int idxRes = intCode[idx + 3];

	intCode[idxRes] = intCode[idxA] + intCode[idxB];
	idx += 4;
}

void IntCodeProcessing::ProcessOpCode2(std::vector<int>& intCode, int& idx)
{
	int idxA = intCode[idx + 1];
	int idxB = intCode[idx + 2];
	int idxRes = intCode[idx + 3];

	intCode[idxRes] = intCode[idxA] * intCode[idxB];
	idx += 4;
}
