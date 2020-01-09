#include "Moon.h"
#include <stdlib.h>

void Moon::ApplyGravity(vector<int> axes, Moon& otherMoon)
{
	for (size_t i = 0; i < axes.size(); i++)
	{
		int axis = axes[i];
		if (axis > 2 || axis < 0)
		{
			throw exception("interdimensional travel detected");
		}
		if (Position[axis] > otherMoon.Position[axis])
		{
			Velocity[axis]--;
			otherMoon.Velocity[axis]++;
		}
		else if (Position[axis] < otherMoon.Position[axis])
		{
			Velocity[axis]++;
			otherMoon.Velocity[axis]--;
		}
	}
}

int Moon::GetTotalEnergy()
{
	return GetKineticEnergy() * GetPotentialEnergy();
}

int Moon::GetKineticEnergy()
{
	return abs(Velocity[0]) + abs(Velocity[1]) + abs(Velocity[2]);
}

int Moon::GetPotentialEnergy()
{
	return abs(Position[0]) + abs(Position[1]) + abs(Position[2]);
}
