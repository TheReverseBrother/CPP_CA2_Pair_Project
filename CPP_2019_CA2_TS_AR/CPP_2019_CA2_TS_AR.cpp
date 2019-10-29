#include "pch.h"


// Method Definitions 
void loadStock();
void outputStock();

// Streams
ifstream in;
ofstream out;

//Stock set

set<StockItem> stock;
set<StockItem>::iterator stockIterator = stock.begin();




int main()
{
	loadStock();


    std::cout << "Hello World!\n";

	StockItem Jeans;
	cout << Jeans.getTitle() << endl;

	StockItem shoes("VANNNS", "BLUE", "XL", 2, 50);

	cout << shoes << endl;

	stock.insert(Jeans);

	outputStock();
}


void loadStock()
{
	in.open("stock-list.txt");

	if (in.fail()) 
	{
		out.open("stock-list.txt");
		loadStock();
	}
}

void outputStock()
{
	out.open("stock-list.txt");
	stockIterator = stock.begin();

	for (stockIterator; stockIterator != stock.end(); stockIterator++) 
	{
		StockItem item = (StockItem)*stockIterator;
		out << item;
	}


}