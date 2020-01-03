#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

#include<string>
#include <vector>

using namespace::std;

class ADVENTOFCODELIB_API Parameter {
public:
	Parameter();
	void Resolve(vector<long long>& memory, int& relativeBase);
	int Mode;
	long long Value;
	long long ResolvedValue;
};