#include "pch.h"

void loadStock();
void outputStock();
ifstream in;
ofstream out;

int main()
{

	loadStock();


    std::cout << "Hello World!\n";

	StockItem Jeans;
	cout << Jeans.getTitle() << endl;

	StockItem shoes("VANNNS", "BLUE", "XL", 2, 50);

	cout << shoes << endl;
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

}