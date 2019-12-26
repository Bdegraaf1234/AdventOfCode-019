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
	int Run(int input);
	IntCodeProcessor() {};
	int ReverseEngineer(int desiredOutcome);
	void WriteMemory(string path);
	static void ProcessOpCode1(std::vector<int>& intCode, int& idx);
	static void ProcessOpCode2(std::vector<int>& intCode, int& idx);
	void ProcessOpCode3(std::vector<int>& intCode, int& idx, int& input);
	int ProcessOpCode4(std::vector<int>& intCode, int& idx);
	vector<int> Memory;
};