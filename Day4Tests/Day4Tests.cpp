#include "pch.h"
#include "CppUnitTest.h"
#include "../AdventOfCodeLib/PasswordDay4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Day4Tests
{
	TEST_CLASS(Day4Tests)
	{
	public:

		TEST_METHOD(CheckPassWordTest1)
		{
			PasswordDay4 pw = PasswordDay4(112233);
			bool res = pw.Check();
			Assert::AreEqual(true, res);
		}

		TEST_METHOD(CheckPassWordTest2)
		{
			PasswordDay4 pw = PasswordDay4(123444);
			bool res = pw.Check();
			Assert::AreEqual(false, res);
		}

		TEST_METHOD(CheckPassWordTest3)
		{
			PasswordDay4 pw = PasswordDay4(111122);
			bool res = pw.Check();
			Assert::AreEqual(true, res);
		}

		TEST_METHOD(GetNumPasswords)
		{
			int numCorrect = PasswordDay4::GetNumPossibilities(264793, 803935);
			Assert::AreEqual(1, numCorrect);
		}
	};
}
