#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"

#include "..\Lab_1_3sem\listInit.c"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyUnitTest
{
	TEST_CLASS(MyUnitTest)
	{
	public:
		
		TEST_METHOD(InitTest)
		{
			myList* man = InitList("tSurname", "tName", "tPatron");
			/*Assert::IsNotNull(man);
			Assert::AreEqual(man->surname,"tSurname");
			Assert::AreEqual(man->name, "tName");
			Assert::AreEqual(man->patron, "tPatron");
			free(man);*/
		}

	};
}
