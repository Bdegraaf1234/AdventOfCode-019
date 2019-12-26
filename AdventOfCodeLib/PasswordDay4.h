#ifdef ADVENTOFCODELIB_EXPORTS
#define ADVENTOFCODELIB_API __declspec(dllexport)
#else
#define ADVENTOFCODELIB_API __declspec(dllimport)
#endif

class ADVENTOFCODELIB_API PasswordDay4 {
public:
	PasswordDay4(int);
	int Password[6];
	bool Check();
	static int GetNumPossibilities(int, int);
};