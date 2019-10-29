#include <iostream>
#include "pch.h"

int main()
{
    std::cout << "Hello World!\n";

	StockItem Jeans;
	cout << Jeans.getTitle() << endl;

	StockItem shoes("VANNNS", "BLUE", SIZE::M, 2, 50);

	/*cout << shoes << endl;*/
}
