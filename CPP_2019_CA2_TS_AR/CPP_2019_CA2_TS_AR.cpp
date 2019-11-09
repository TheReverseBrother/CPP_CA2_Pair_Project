#include "pch.h"


// Method Definitions 
bool removeStock(const StockItem& item);
bool removeSale(const Sale& sale);
int intValidator();
double doubleValidator();
//Stock set
multiset<StockItem> stock;
multiset<Sale> Sales;
list<SalesAnalysis> AnalysisList;



int main()
{
	stock = StockItem::loadStock();
	Sales = Sale::loadSales();
	AnalysisList = SalesAnalysis::loadAnalysises();



	for (StockItem s : stock)
	{
		cout << s << endl;
	}
	for (Sale s : Sales)
	{
		cout << s << endl;
	}
	for (SalesAnalysis s : AnalysisList)
	{
		cout << s;
	}

	

	StockItem::saveStock(stock);
	Sale::saveSales(Sales);
	SalesAnalysis::saveAnalysises(AnalysisList);
}

bool removeStock(const StockItem& item)
{
	auto it = find(stock.begin(), stock.end(), item);
	if (it != stock.end())
	{
		stock.erase(it);
		return true;
	}
	return false;
}
bool removeSale(const Sale& sale)
{
	auto it = find(Sales.begin(), Sales.end(), sale);
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