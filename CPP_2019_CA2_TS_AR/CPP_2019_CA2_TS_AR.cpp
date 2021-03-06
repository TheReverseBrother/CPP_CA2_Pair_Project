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




int main()
{
	//map<int, StockItem> m = store.getStock();
	
	std::cout << "" << endl;


	mainMenu();


	createSale();
	map<int, Sale> m = store.getSales();
	for (auto i : m)
	{
		i.second.print();
	}
}

/*
Author Tomas
Used to create a sale a user can only select valid items and cannot select quantitys that do not exist.
It also decrements the stock by the quantity chosen
*/
void createSale() 
{
	bool runOnce = false;//used to change message
	bool running = true;//used to allow picking
	int ID = 0;
	int quantity = 0;
	float totalValue = 0;
	list<StockItem> items;
	while (running) //Runs the Picking Function
	{
		
		bool runningSelector = true;//used for selecting an object
		bool quantitySelector = true; // Used for selecting a Quantity
		
		//print stock
		store.printStock();

		//One Item must be chosen so changes message based on runs
		if (runOnce)
		{
			std::cout << "Please Select An Item By ID(Press 0 to Finish Selecting)" << endl;
		}
		else
		{
			std::cout << "Please Select An Item By ID" << endl;
			std::cout << "Enter any Letter to return to sales Menu" << endl;
			runOnce = true;
		}

		//Selecting an item validator
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

		//Makes user check quantity
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

	running = true;
	
	while (running)
	{
		std::cout << "Please Enter Assistant Name" << endl;
		string name;
		getline(cin, name);
		time_t timeNow = time(0);
		try
		{
			Sale sale(name, items, totalValue, timeNow);
			store.addSale(sale);
			running = false;
		}
		catch (domain_error & e)
		{
			std::cout << "Assistant Name to short " << endl;
		}
	}
	addSaleMenu();
}

/**
Author: Tomas
Checks if a new sale has occured and then creates an analysis  if one has otherwise says it cant
*/
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

bool removeStock(const int key)
{
	auto it = (*stock).find(key);
	if (it != (*stock).end())
	{
		(*stock).erase(it);
		return true;
	}
	return false;
}
bool removeSale(const int key)
{
	auto it = sales.find(key);
	if (it != sales.end())
	{
		sales.erase(it);
		return true;
	}
	return false;
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