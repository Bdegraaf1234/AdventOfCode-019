#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

using namespace::std;

#include <string>
#include <vector>

class ADVENTOFCODELIB_API Parsing {
public:
	static int GetNumberOfLines(string);
	static vector<int> ParseInputDay1(string);
	static vector<vector<string>> ParseInputDay3(string);
	static vector<int> ParseIntCodeProgram(string path);
	static vector<string> ParseInputDay6(string path);
};
