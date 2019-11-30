#include "Store.h"

Store::Store()
{
	this->stock = StockItem::loadStock();
	this->sales = Sale::loadSales();
	this->analysisList = SalesAnalysis::loadAnalysises();
	loadStaticValues();
}

Store::~Store()
{
	saveStaticValues();
	SaveAll();
}

bool Store::addStockItem(StockItem& item)
{
	int id = item.getID();
	this->stock.insert(make_pair(id,item));
	return true;
}

bool Store::addSale(Sale& sale)
{
	int id = sale.getID();
	this->sales.insert(make_pair(id, sale));

	cout << "IN HERE" << endl;
	return false;
}

bool Store::addAnalysis(SalesAnalysis& analysis)
{
	this->analysisList.push_back(analysis);
	return true;
}

bool Store::removeStockItem(int& ID)
{
	map<int, StockItem>::iterator it;

	it = this->stock.find(ID);

	if (it != this->stock.end())
	{
		this->stock.erase(it);
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

bool Store::removeSale(int& ID)
{
	map<int, Sale>::iterator it;
	it = this->sales.find(ID);

	if (it != this->sales.end())
	{
		this->sales.erase(it);
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

bool Store::checkStockItemExists(int &ID)
{
	map<int, StockItem>::iterator it;

	it = this->stock.find(ID);

	if (it != this->stock.end())
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

bool Store::decrementStockQuantity(int &ID, int &Quantity)
{
	auto it = stock.find(ID);
	
	int s = it->second.getQuantity();

	int x = s - Quantity;

	if (x < 1)
	{
		return false;
	}
	else
	{
		it->second.setQuantity(x);
		return true;
	}

	return false;
}

StockItem Store::searchByID(int& ID)
{

	return stock.find(ID)->second;
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
	return this->stock;
}

map<int, Sale>& Store::getSales()
{
	return this->sales;
}

list<SalesAnalysis> Store::getAnalysises()
{
	return this->analysisList;
}

 void Store::SaveAll()
{
	StockItem::saveStock(this->stock);
	Sale::saveSales(this->sales);
	SalesAnalysis::saveAnalysises(this->analysisList);
}

void Store::LoadAll()
{

}
