#pragma once
#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

#include <vector>

using namespace::std;

class ADVENTOFCODELIB_API Moon
{
public:
	vector<int> Position = { 0, 0, 0 };
	vector<int> Velocity = { 0, 0, 0 };
	void ApplyGravity(vector<int> axes, Moon& otherMoon);
	int GetTotalEnergy();
	int GetKineticEnergy();
	int GetPotentialEnergy();
	friend bool operator==(const Moon& lhs, const Moon& rhs) {
		if (lhs.Position == rhs.Position &&
			lhs.Velocity == rhs.Velocity
		) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

