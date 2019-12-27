#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

#include <vector>
#include <string>

using namespace::std;

class ADVENTOFCODELIB_API OrbitingObject {
public:
	OrbitingObject(string id);
	string Id;
	string OrbitalCenter;
	vector<string> ConnectedObjects;
	int Distance;
	bool operator==(const OrbitingObject& obj2) const
	{
		if (this->Id.compare(obj2.Id) == 0)
			return true;
		else
			return false;
	}
};