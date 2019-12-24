#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

using namespace::std;

#include <vector>

class ADVENTOFCODELIB_API IntCodeProcessing {
public:
	static vector<int> Run(std::vector<int>);
	static void ProcessOpCode1(std::vector<int>& intCode, int& idx);
	static void ProcessOpCode2(std::vector<int>& intCode, int& idx);
};