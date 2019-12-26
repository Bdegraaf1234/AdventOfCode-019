#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

using namespace::std;

#include <vector>
#include <map>
#include<string>

class ADVENTOFCODELIB_API Wire {
public:
	map<int, vector<int>> Positions;
	vector<string> Route;
	void SetPath(vector<string>);
	map<int, vector<int>> GetOverlapMap(Wire);
	int GetNumSteps(int x, int y);
};