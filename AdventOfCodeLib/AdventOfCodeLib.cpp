// AdventOfCodeLib.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "AdventOfCodeLib.h"


// This is an example of an exported variable
ADVENTOFCODELIB_API int nAdventOfCodeLib=0;

// This is an example of an exported function.
ADVENTOFCODELIB_API int fnAdventOfCodeLib(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CAdventOfCodeLib::CAdventOfCodeLib()
{
    return;
}