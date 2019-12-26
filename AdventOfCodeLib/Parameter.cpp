#include "Parameter.h"

Parameter::Parameter()
{
}

void Parameter::Resolve(vector<int>& memory)
{
	int outInt = -1;
	if (Mode == 0)
	{
		outInt = memory[Value];
	}
	if (Mode == 1)
	{
		outInt = Value;
	}
	ResolvedValue = outInt;
}
