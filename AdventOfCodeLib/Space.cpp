#include "Space.h"

void Space::ApplyGravity(vector<int> axes)
{
	for (size_t i = 0; i < Moons.size(); i++)
	{
		for (size_t j = i + 1; j < Moons.size(); j++)
		{
			Moons[i].ApplyGravity(axes, Moons[j]);
		}
	}
}

int Space::GetPeriod(int axis, int moon) 
{
	Time = 0;
	int startPos = Moons[moon].Position[axis];
	int startVel = Moons[moon].Velocity[axis];
	AdvanceTime({ axis });
	while (Moons[moon].Position[axis] != startPos || Moons[moon].Velocity[axis] != startVel)
	{
		AdvanceTime({ axis });
	}
	return Time;
}

void Space::AdvanceTime(vector<int> axes)
{
	Time++;
	ApplyGravity(axes);
	for (size_t i = 0; i < Moons.size(); i++)
	{
		for (size_t j = 0; j < axes.size(); j++)
		{
			int axis = axes[j];
			Moons[i].Position[axis] += Moons[i].Velocity[axis];
		}
	}
}

int Space::GetTotalEnergy()
{
	int energy = 0;
	for (size_t i = 0; i < Moons.size(); i++)
	{
		energy += Moons[i].GetTotalEnergy();
	}
	return energy;
}
