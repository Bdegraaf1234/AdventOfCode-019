#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

using namespace::std;

#include <string>
#include <vector>
#include "Parsing.h"

class ADVENTOFCODELIB_API IntCodeProcessor {
public:
	IntCodeProcessor(string path);
	static int RunMultiProcessor(int input, vector<int> inputPhase, vector<IntCodeProcessor> processors);
	int Run(vector<int> input);
	int RunUntilFirstOutput(int input);
	int RunUntilFirstOutput(vector<int> input);
	int Run(int input);
	IntCodeProcessor() {};
	int ReverseEngineer(int desiredOutcome);
	void WriteMemory(string path);
	vector<int> Memory;
	int Pointer;
	int Output;
};