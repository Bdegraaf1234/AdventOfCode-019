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
	int Mode;
	int Value;
	int ResolvedValue;
	void Resolve(vector<int>& memory);
};