#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

#include "Wire.h"

class ADVENTOFCODELIB_API ElectricalGrid {
public:
	ElectricalGrid(string);
	Wire WireA;
	Wire WireB;
	int GetShortestManhattanDistance();
	int GetLowestNumSteps();
};