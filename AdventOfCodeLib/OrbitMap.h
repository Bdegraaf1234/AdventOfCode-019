#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

#include "OrbitingObject.h"
#include <vector>
#include <string>

using namespace::std;

class ADVENTOFCODELIB_API OrbitMap {
public:
	OrbitMap(vector<string> input);
	vector<OrbitingObject> ObjectsInOrbit;
	int CountOrbits(OrbitingObject start);
	void CalculateDistanceToObjects(OrbitingObject start);
};