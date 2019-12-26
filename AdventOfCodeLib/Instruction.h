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
	Instruction(int opcode, int pointer, int input);
	int Pointer;
	vector<Parameter> Parameters;
	int Identifier;
	int Input;
	int Output;
	int Execute(vector<int>& memory, int& pointer);
	int CountNumbers(int);
};