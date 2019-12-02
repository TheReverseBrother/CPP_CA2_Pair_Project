#include "pch.h"
#include "Store.h"
#include "User-interface.h"

// Method Definitions 
//SalesAnalysis createSaleAnalysis(time_t lastAnalysis);
void createSale();
int intValidator();
double doubleValidator();
float floatValidator();

void createAnalysis();
Store store;



int main()
{
	//map<int, StockItem> m = store.getStock();
	
	//std::cout << "" << endl;

	//createSale();
	//store.printSales();

	bool yes = store.checkIfNewSales();

	if (yes)
	{
		cout << "Hello Ladies" << endl;
	}

	createAnalysis();
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
		
		store.printStock();
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
			else
			{
				bool checkExists = store.checkStockItemExists(ID);

				if (checkExists)
				{
					StockItem s = store.searchByID(ID);

					if (s.getQuantity() > 0)
					{
						runningSelector = false;
					}
					else
					{
						cout << "Invalid Quantity for Sale Please Select Another Item" << endl;
					}
				}
				else
				{
					cout << "Invalid ID Please Select Again" << endl;
				}
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
	time_t timeNow = time(0);
	Sale sale(name,items,totalValue,timeNow);
	store.addSale(sale);
}

void createAnalysis()
{
	bool newSale = store.checkIfNewSales();
	

	if (newSale)
	{
		cout << "Creating New Sale Analysis" << endl;
		store.createSaleAnalysis();
	}
	else
	{
		cout << "Unable To Create Analysis A Sale Hasnt Occured Since The Last Analysis" << endl;
	}
}


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