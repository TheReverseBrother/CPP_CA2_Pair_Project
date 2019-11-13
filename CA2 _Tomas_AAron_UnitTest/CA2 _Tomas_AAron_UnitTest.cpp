#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <functional>

#include "../CPP_2019_CA2_TS_AR/pch.h"
#include "../CPP_2019_CA2_TS_AR/StockItem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CA2TomasAAronUnitTest
{
	TEST_CLASS(CA2TomasAAronUnitTest)
	{
	public:
		
		TEST_METHOD(Test_Default_Constructor)
		{
			StockItem s1;
			int id= 1 ;
			string title =  "Jeans";
			string color = "Blue";
			string size = "XL";
			int quantity = 10;
			float cost = 2.0;

			Assert::AreEqual(s1.getID(),id);
			Assert::AreEqual(s1.getColor(),color);
			Assert::AreEqual(s1.getTitle(),title);
			Assert::AreEqual(s1.getSize(),size);
			Assert::AreEqual(s1.getQuantity(),quantity);
			Assert::AreEqual(s1.getCost(),cost);
		}

		TEST_METHOD(setTitle_Test)
		{
			//Test One Char
			auto func = [] {
				StockItem t;
				string title = "2";
				t.setTitle(title);
			};

			Assert::ExpectException<domain_error>(func);

			//Test 2 Char
			auto func2 = [] {
				StockItem t;
				string title = "WW";
				t.setTitle(title);
			};

			Assert::ExpectException<domain_error>(func2);

			//Test 3 Char
			auto func3 = [] {
				StockItem t;
				string title = "WWW";
				t.setTitle(title);
			};

			Assert::ExpectException<domain_error>(func3);

			//Test 4 Char
			StockItem s;
			string title = "Jean";
			s.setTitle(title);

			Assert::AreEqual(s.getTitle(),title);

			//Test Long String
			
			title = "Purple Hoodie";
			s.setTitle(title);

			Assert::AreEqual(s.getTitle(), title);
		}


		TEST_METHOD(setColor_Test)
		{
			StockItem t;
			string color = "2";

			//Test One Char
			auto func = [&] {
				t.setColor(color);
			};

			Assert::ExpectException<domain_error>(func);

			//Test 2 Char
			color = "WW";
			auto func1 = [&] {
				t.setColor(color);
			};

			Assert::ExpectException<domain_error>(func1);

			//Test 3 Char
			color = "WWW";
			t.setColor(color);

			Assert::AreEqual(t.getColor(), color);


			//Test 4 Char
			color = "WWWW";
			t.setColor(color);

			Assert::AreEqual(t.getColor(),color);

			//Test Long String
			color = "Eggshell White";
			t.setColor(color);

			Assert::AreEqual(t.getColor(), color);

		}
	
		TEST_METHOD(setQuantity_Test)
		{
			StockItem t;
			int num = 0;

			//Test 0 
			auto func = [&] {
				t.setQuantity(num);
			};

			Assert::ExpectException<domain_error>(func);

			//Test 1
			num = 1;
			t.setQuantity(num);

			Assert::AreEqual(t.getQuantity(), num);
			//Test 10
			num = 10;
			t.setQuantity(num);

			Assert::AreEqual(t.getQuantity(),num);

		}
};
}
