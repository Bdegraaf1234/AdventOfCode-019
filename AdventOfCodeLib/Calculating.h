#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

using namespace::std;

#include <vector>

class ADVENTOFCODELIB_API Calculating {
public:
	static int CalculateModuleFuelRequirement(int);
	static int CalculateTotalFuelRequirement(std::vector<int>);
	static int CalculateTotalFuelRequirementIncludingFuel(std::vector<int>);
	static int CalculateModuleFuelRequirementIncludingFuel(int);
};
