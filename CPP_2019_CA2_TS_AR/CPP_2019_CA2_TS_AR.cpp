#include "pch.h"


// Method Definitions 
void loadStock();
void outputStock();

// Streams
ifstream in;
ofstream out;

//Stock set

multiset<StockItem> stock;
multiset<StockItem>::iterator stockBegin = stock.begin();
multiset<StockItem>::iterator stockEnd = stock.cend();




int main()
{
	loadStock();


    std::cout << "Hello World!\n";

	StockItem Jeans;
	cout << Jeans.getTitle() << endl;

	StockItem shoes("VANNNS", "BLUE", "XL", 2, 50);
	StockItem Jacket = StockItem("Jacket", "RED", "XL", 2, 50);

	cout << shoes << endl;

	stock.insert(Jeans);
	stock.insert(shoes);
	stock.insert(Jacket);
	



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
	stockBegin = stock.begin();

	for (auto x : stock)
	{
		StockItem item = (StockItem)x;
		out << item;
	}

}