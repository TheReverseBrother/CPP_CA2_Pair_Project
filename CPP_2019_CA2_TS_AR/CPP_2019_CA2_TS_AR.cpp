#include "pch.h"


// Method Definitions 
bool removeStock(const StockItem& item);
bool removeSale(const Sale& sale);
// Streams
ifstream in;
ofstream out;

//Stock set
multiset<StockItem> stock;
multiset<Sale> Sales;
list<SalesAnalysis> AnalysisList;
multiset<StockItem>::iterator stockBegin = stock.begin();
multiset<StockItem>::iterator stockEnd = stock.cend();




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
