#include "pch.h"
#include "Store.h"
#include "User-interface.h"

// Method Definitions 
//SalesAnalysis createSaleAnalysis(time_t lastAnalysis);
void createSale();
int intValidator();
double doubleValidator();
float floatValidator();
Store store;



int main()
{
	//map<int, StockItem> m = store.getStock();
	
	std::cout << "" << endl;

	//createSale();
	map<int, Sale> m = store.getSales();
	for (auto i : m)
	{
		i.second.print();
	}
}


void createSale() 
{
	bool runOnce = false;//used to change message
	bool running = true;//used to allow picking
	int ID = 0;
	int quantity = 0;
	float totalValue = 0;
	list<StockItem> items;
	while (running)
	{
		map<int, StockItem> stockList = store.getStock();
		bool runningSelector = true;//used for selecting an object
		bool quantitySelector = true;
		
		printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "ID", "Item", "Color", "Size", "Quantity", "Unit Price");//Print Table Header
		for (auto i : stockList)
		{
			i.second.print();
		}
		if (runOnce)
		{
			std::cout << "Please Select An Item By ID(Press 0 to Finish Selecting)" << endl;
		}
		else
		{
			std::cout << "Please Select An Item By ID" << endl;
			runOnce = true;
		}

		while (runningSelector)
		{
			ID = intValidator();//get ID

			if (ID == 0 && runOnce)
			{
				runningSelector = false;
				running = false;
				quantitySelector = false;
			}//can only terminate when one item selected
			
			bool checkExists = store.checkStockItemExists(ID);

			if (checkExists)
			{
				runningSelector = false;
			}
		}

		if (quantitySelector)
		{
			std::cout << endl;
			std::cout << "Please Select A Quantity To Purchase:" << endl;
		}

		while (quantitySelector)
		{
			quantity = intValidator();
			bool valid  = store.decrementStockQuantity(ID, quantity);
			if (valid)
			{
				StockItem newItem = store.searchByID(ID);
				totalValue += newItem.getCost() * quantity;
				newItem.setQuantity(quantity);
				items.push_back(newItem);
				quantitySelector = false;
			}
			else
			{
				std::cout << endl;
				std::cout << "Invalid Quantity Please Try Again" << endl;
			}
		}
	}
	std::cout << endl;
	std::cout << "Please Enter Assistant Name" << endl;
	string name;
	getline(cin, name);
	Sale sale(name,items,totalValue);
	store.addSale(sale);
}



//SalesAnalysis createSaleAnalysis(time_t time)
//{
//	time_t lastAnalysis = /*(time_t)1573121444;*/time;
//	SalesAnalysis newAnalysis(lastAnalysis);
//	
//	printf("%-10s %-20s %-10s %-15s %-15s\n", "ID", "Sale Assistant","No. Items","Total Price","Date");
//	newAnalysis = for_each(Sales.begin(),Sales.end(), newAnalysis);
//
//	cout << endl;
//	cout << "New Analysis Generated: " << endl;
//	printf("%-15s %-20s %-15s %-15s\n", "ID", "Last Analysis", "Total Value", "Date Generated");
//	newAnalysis.print();
//	return newAnalysis;
//}

//bool removeStock(const int key)
//{
//	auto it = stock.find(key);
//	if (it != stock.end())
//	{
//		stock.erase(it);
//		return true;
//	}
//	return false;
//}
//bool removeSale(const int key)
//{
//	auto it = Sales.find(key);
//	if (it != Sales.end())
//	{
//		Sales.erase(it);
//		return true;
//	}
//	return false;
//}

/*
Author: Tomas
This function takes in a line from command line and parses it to an int 
if arguement is invalid it makes you try again till valid arguement is passed.
*/
inline int intValidator()
{
	string data;
	int num;
	bool running = true;
	while (running)
	{
		try
		{
			getline(cin, data);
			num = stoi(data);

			running = false;
		}
		catch (invalid_argument e)
		{
			cout << "Invalid Arguement Please try Again" << endl;
		}
		catch (out_of_range e)
		{
			cout << "Out Of Range Please Try Again" << endl;
		}
		catch (exception e)
		{
			cout << "Unknown Error has Occured Please Try Again" << endl;
		}
	}

	return num;
}

/*
Author: Tomas
This function takes in a line from command line and parses it to an double
if arguement is invalid it makes you try again till valid arguement is passed.
*/
inline double doubleValidator()
{
	string data;
	double num;
	bool running = true;
	while (running)
	{
		try
		{
			getline(cin, data);
			num = stod(data);

			running = false;
		}
		catch (invalid_argument e)
		{
			cout << "Invalid Arguement Please try Again" << endl;
		}
		catch (out_of_range e)
		{
			cout << "Out Of Range Please Try Again" << endl;
		}
		catch (exception e)
		{
			cout << "Unknown Error has Occured Please Try Again" << endl;
		}
	}

	return num;
}

/*
Author: Tomas
This function takes in a line from command line and parses it to an float
if arguement is invalid it makes you try again till valid arguement is passed.
*/
inline float floatValidator()
{
	string data;
	float num;
	bool running = true;
	while (running)
	{
		try
		{
			getline(cin, data);
			num = stof(data);

			running = false;
		}
		catch (invalid_argument e)
		{
			cout << "Invalid Arguement Please try Again" << endl;
		}
		catch (out_of_range e)
		{
			cout << "Out Of Range Please Try Again" << endl;
		}
		catch (exception e)
		{
			cout << "Unknown Error has Occured Please Try Again" << endl;
		}
	}

	return num;
}

/*
Author: Tomas
takes in the number of choices valid in a menu and only returns when a valid choice has been selected
*/
inline int menuValidator(int noOfChoices)
{
	bool running = true;
	int choice;
	while (running)
	{
		choice = intValidator();
		if (choice >= 0 && choice <= noOfChoices)
		{
			running = false;
		}
		else
		{
			cout << "Invalid Choice Please Choose A Designated Number" << endl;
		}
	}
}