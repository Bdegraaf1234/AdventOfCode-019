#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

#include "Parameter.h"
#include "IntCodeProcessor.h"
#include <vector>

using namespace::std;

class ADVENTOFCODELIB_API Instruction {
public:
	Instruction(int opcode, int pointer, long long input);
	int Pointer;
	vector<Parameter> Parameters;
	int Identifier;
	long long Input;
	long long Output;
	long long Execute(vector<long long>& memory, int& pointer, int& relativeBase, string outPath);
	int CountNumbers(int);
};