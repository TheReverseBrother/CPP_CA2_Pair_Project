#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP_2019_CA2_TS_AR/StockItem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CA2TomasAAronUnitTest
{
	TEST_CLASS(CA2TomasAAronUnitTest)
	{
	public:
		
		TEST_METHOD(Test_Constructor)
		{
			StockItem s;
			int id = 1;

			Assert::AreEqual(s.getID(),id);


		}
	};
}
