#include "pch.h"
#include "User-interface.h"

// Method Definitions 
bool removeStock(const StockItem& item);
bool removeSale(const Sale& sale);
SalesAnalysis createSaleAnalysis(time_t lastAnalysis);
int intValidator();
double doubleValidator();
float floatValidator();
//Stock set
map<int,Sale> Sales;
list<SalesAnalysis> AnalysisList;



int main()
{
	//stock = StockItem::loadStock();
	Sales = Sale::loadSales();
	//AnalysisList = SalesAnalysis::loadAnalysises();
	//cout << endl;
	//cout << endl;

	//cout << "Welcome" << endl;
	//auto StockIT = stock.begin();
	//StockItem temp;
	//for (int i = 0; i < stock.size(); i++) 
	//{
	//	temp = *StockIT;

	//	cout << "id " << temp.getTitle() << "";
	//	StockIT++;
	//	
	//}

	//cout << endl;
	//


	//mainMenu();


	for (auto i : Sales)
	{
		cout << i.second << endl;
	}


 //   std::cout << "Hello World!\n";



	//StockItem Jeans;
	//cout << Jeans.getTitle() << endl;
	//StockItem vanns(152, "VANNNS", "BLUE", "XL", 2, 50);
	//StockItem Jacket = StockItem("Jacket", "RED", "XL", 2, 50);
	//StockItem shoe(1, "Jacket", "RED", "XL", 2, 50);
	//StockItem shoes(1, "Jacket", "RED", "XL", 2, 50);
	//StockItem jeans;
	//cout<<"Jacket ID  "<<Jacket.getID()<<endl;
	//cout << "Jean ID  " << jeans.getID() << endl;
	//list<StockItem> itemList;





	//SalesAnalysis si = *AnalysisList.rbegin();
	//time_t lastAnalysis = si.getDateOfCreation();
	//SalesAnalysis s = createSaleAnalysis(lastAnalysis);
	//int x = intValidator();
	//StockItem::saveStock(stock);
	Sale::saveSales(Sales);
	//SalesAnalysis::saveAnalysises(AnalysisList);
}

SalesAnalysis createSaleAnalysis(time_t time)
{
	time_t lastAnalysis = /*(time_t)1573121444;*/time;
	SalesAnalysis newAnalysis(lastAnalysis);
	
	printf("%-10s %-20s %-10s %-15s %-15s\n", "ID", "Sale Assistant","No. Items","Total Price","Date");
	newAnalysis = for_each(Sales.begin(),Sales.end(), newAnalysis);

	cout << endl;
	cout << "New Analysis Generated: " << endl;
	printf("%-15s %-20s %-15s %-15s\n", "ID", "Last Analysis", "Total Value", "Date Generated");
	newAnalysis.print();
	return newAnalysis;
}

bool removeStock(const int key)
{
	auto it = stock.find(key);
	if (it != stock.end())
	{
		stock.erase(it);
		return true;
	}
	return false;
}
bool removeSale(const int key)
{
	auto it = Sales.find(key);
	if (it != Sales.end())
	{
		Sales.erase(it);
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