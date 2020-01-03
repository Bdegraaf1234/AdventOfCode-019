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
	static long long RunMultiProcessor(long long input, vector<int> inputPhase, vector<IntCodeProcessor> processors);
	long long Run(vector<long long> input);
	long long RunUntilFirstOutput(long long input);
	long long RunUntilFirstOutput(vector<long long> input);
	long long Run(long long input);
	long long RunForceInput(long long input);
	IntCodeProcessor() {};
	long long ReverseEngineer(long long desiredOutcome);
	void WriteMemory(string path);
	vector<long long> Memory;
	int Pointer;
	long long Output;
	int RelativeBase;
	string OutPath;
};