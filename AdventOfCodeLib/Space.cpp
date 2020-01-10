#include "Space.h"
#include <map>
#include "Calculating.h"

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

int Space::GetPeriod() 
{
	Time = 0;
	
	AdvanceTime({ 0, 1, 2 });
	vector<int> velStateX = vector<int>();
	vector<int> velStateY = vector<int>();
	vector<int> velStateZ = vector<int>();
	for (size_t i = 0; i < Moons.size(); i++)
	{
		velStateX.push_back(Moons[i].Velocity[0]);
		velStateY.push_back(Moons[i].Velocity[1]);
		velStateZ.push_back(Moons[i].Velocity[2]);
	}
	int xsteps = -1;
	int ysteps = -1;
	int zsteps = -1;
		while (xsteps == -1 || ysteps == -1 || zsteps == -1 )
		{
			velStateX = vector<int>();
			velStateY = vector<int>();
			velStateZ = vector<int>();
			AdvanceTime({0,1,2});
			for (size_t i = 0; i < Moons.size(); i++)
			{
				velStateX.push_back(Moons[i].Velocity[0]);
				velStateY.push_back(Moons[i].Velocity[1]);
				velStateZ.push_back(Moons[i].Velocity[2]);
			}
			if (velStateX == vector<int>{0, 0, 0, 0}&& xsteps == -1)
			{
				xsteps = Time;
			}
			if (velStateY == vector<int>{0, 0, 0, 0}&& ysteps == -1)
			{
				ysteps = Time;
			}
			if (velStateZ == vector<int>{0, 0, 0, 0}&& zsteps == -1)
			{
				zsteps = Time;
			}
		}
		return Calculating::calculateLeastCommonMultiple({xsteps, ysteps, zsteps});
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
