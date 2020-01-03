#include "Parameter.h"

Parameter::Parameter()
{
}

void Parameter::Resolve(vector<long long>& memory, int& relativeBase)
{
	long long outInt = -1;
	if (Mode == 0)
	{
		outInt = memory[Value];
	}
	if (Mode == 1)
	{
		outInt = Value;
	}
	if (Mode == 2)
	{
		//TODO write destination shoudbe a separate field
		outInt = memory[Value + relativeBase];
		Value = Value + relativeBase;
	}
	ResolvedValue = outInt;
}
