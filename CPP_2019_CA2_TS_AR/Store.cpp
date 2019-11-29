#include "Store.h"

Store::Store()
{
	LoadAll();
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
	return stock;
}

map<int, Sale>& Store::getSales()
{
	return this->sales
}

list<SalesAnalysis> Store::getAnalysises()
{
	return this->analysisList;
}

void Store::SaveAll()
{
}

void Store::LoadAll()
{
	this->stock = StockItem::loadStock();
	this->sales = Sale::loadSales();
	this->analysisList = SalesAnalysis::loadAnalysises();
}
