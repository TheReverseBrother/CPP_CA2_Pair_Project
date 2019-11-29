#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
}

bool Store::addStockItem(StockItem& item)
{
	return false;
}

bool Store::addSale(Sale& sale)
{
	return false;
}

bool Store::addAnalysis(SalesAnalysis& analysis)
{
	return false;
}

bool Store::removeStockItem(int& ID)
{
	return false;
}

bool Store::removeSale(int& ID)
{
	return false;
}

StockItem Store::searchByID(int& ID)
{
	return StockItem();
}

StockItem Store::searchByPLACEHOLDER()
{
	return StockItem();
}

StockItem Store::searchByPLACEHOLDER2()
{
	return StockItem();
}

map<int, StockItem>& Store::getStock()
{
	// TODO: insert return statement here
}

map<int, Sale>& Store::getSales()
{
	// TODO: insert return statement here
}

list<SalesAnalysis> Store::getAnalysises()
{
	return list<SalesAnalysis>();
}

void Store::SaveAll()
{
}

void Store::LoadAll()
{
}
