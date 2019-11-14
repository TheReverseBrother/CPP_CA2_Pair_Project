#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <functional>

#include "../CPP_2019_CA2_TS_AR/pch.h"
#include "../CPP_2019_CA2_TS_AR/StockItem.h"
#include "../CPP_2019_CA2_TS_AR/Sale.h"
#include "../CPP_2019_CA2_TS_AR/SalesAnalysis.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CA2TomasAAronUnitTest
{
	TEST_CLASS(Test_StockItem)
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

		TEST_METHOD(setCost_Test)
		{
			StockItem t;
			float cost = -0.00;

			//Test -1.00
			auto func = [&] {
				t.setCost(cost);
			};

			Assert::ExpectException<domain_error>(func);

			//Test 0.00
			cost = 0.00;
			auto func1 = [&] {
				t.setCost(cost);
			};

			Assert::ExpectException<domain_error>(func1);

			//Test 12.00
			cost = 12.00;
			t.setCost(cost);

			Assert::AreEqual(t.getCost(),cost);


		}
};

	TEST_CLASS(Test_Sale)
	{
		TEST_METHOD(Test_Default_Constructor)
		{
			Sale s;
			time_t timeNow = time(0);
			int id = 1;
			string assistant = "George Default";

			Assert::AreEqual(s.getID(),id);
			Assert::AreEqual(s.getTime(),timeNow);
			Assert::AreEqual(s.getAssistant(),assistant);
		}

		TEST_METHOD(setTime_Test)
		{
			Sale s;
			time_t timeNow = time(0);
			s.setTime(timeNow);

			Assert::AreEqual(s.getTime(),timeNow);
		}

		TEST_METHOD(setItems_Test)
		{
			Sale s;
			list<StockItem> items;
			StockItem st;
			auto func = [&] {
				s.setItems(items);
			};

			Assert::ExpectException<domain_error>(func);

			//test With items
			items.push_back(st);
			s.setItems(items);

			list<StockItem> itemsInClass = s.getItems();
			int size1 = items.size();
			int size2 = itemsInClass.size();

			Assert::AreEqual(size1,size2);

		}

		TEST_METHOD(setAssistant_Test)
		{
			Sale s;
			string name = "J";


			//Test 1 Char
			auto func = [&] {
				s.setAssistant(name);
			};

			Assert::ExpectException<domain_error>(func);


			//Test 2 Char
			name = "JJ";
			auto func1 = [&] {
				s.setAssistant(name);
			};

			Assert::ExpectException<domain_error>(func1);

			//Test 3 Char
			name = "Jim";
			auto func2 = [&] {
				s.setAssistant(name);
			};

			Assert::ExpectException<domain_error>(func2);

			//Test 4 Char
			name = "John";
			s.setAssistant(name);

			Assert::AreEqual(s.getAssistant(),name);

			//Test Long String
			name = "John Quincy Adams";
			s.setAssistant(name);

			Assert::AreEqual(s.getAssistant(), name);

		}

		TEST_METHOD(removeItem_Test)
		{
			Sale s;
			list<StockItem> items;
			StockItem st;
			int size1, size2;
			items.push_back(st);
			s.setItems(items);

			list<StockItem> itemsInSale = s.getItems();
			size1 = items.size();
			size2 = itemsInSale.size();
			Assert::AreEqual(size1,size2);

			bool removed = s.removeItem(st);
			Assert::IsTrue(removed);

		}
	};

	TEST_CLASS(Test_SaleAnalysis)
	{
		TEST_METHOD(Test_Default_Constructor)
		{
			SalesAnalysis s;
			int id = 0;
			time_t timeNow = time(0);
			float price = 1.00;

			Assert::AreEqual(s.getID(),id);
			Assert::AreEqual(s.getDateOfCreation(),timeNow);
			Assert::AreEqual(s.getTotalValue(),price);
		}

		TEST_METHOD(Test_Regular_Constructor)
		{

		}
	};
}
