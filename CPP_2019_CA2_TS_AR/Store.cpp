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
	auto it = this->stock.find(id);
	
	if (it == this->stock.end())
	{
		this->stock.insert(make_pair(id, item));
		return true;
	}


	return false;
}

bool Store::addSale(Sale& sale)
{
	int id = sale.getID();
	auto it = this->sales.find(id);

	if (it != sales.end())
	{
		this->sales.insert(make_pair(id, sale));
		return true;
	}
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

	if (x < 0)
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

void Store::printSales()
{
	printf("%-10s %-20s %-10s %-15s %-15s\n","ID","Assistant","No. Items","Total Price","Date");
	for (pair<int,Sale> i : this->sales)
	{
		i.second.print();
	}
}

void Store::printStock()
{
	printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "ID", "Item", "Color", "Size", "Quantity", "Unit Price");
	for (pair<int, StockItem> i : this->stock)
	{
		i.second.print();
	}
}

void Store::printSales(map<int, Sale>& s)
{
	printf("%-10s %-20s %-10s %-15s %-15s\n", "ID", "Assistant", "No. Items", "Total Price", "Date");
	for (pair<int, Sale> x : s)
	{
		x.second.print();
	}
}

void Store::printStock(map<int, StockItem>& s)
{
	printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "ID", "Item", "Color", "Size", "Quantity", "Unit Price");
	for (pair<int, StockItem> i : s)
	{
		i.second.print();
	}
}

void Store::createSaleAnalysis()
{
	time_t lastAnalysis = getLastAnalysisDate();
	SalesAnalysis newAnalysis(lastAnalysis);

	printf("%-10s %-20s %-10s %-15s %-15s\n", "ID", "Sale Assistant", "No. Items", "Total Price", "Date");
	newAnalysis = for_each(sales.begin(), sales.end(), newAnalysis);

	cout << endl;
	cout << "New Analysis Generated: " << endl;
	printf("%-15s %-20s %-15s %-15s\n", "ID", "Last Analysis", "Total Value", "Date Generated");
	newAnalysis.print();

	addAnalysis(newAnalysis);
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

time_t Store::getLastAnalysisDate()
{
	SalesAnalysis s = *analysisList.rbegin();
	time_t lastAnalysis = s.getDateOfCreation();
	return lastAnalysis;
}

bool Store::checkIfNewSales()
{
	time_t lastAnalysis = getLastAnalysisDate();

	bool newSales = any_of(sales.begin(), sales.end(), [lastAnalysis](pair<int,Sale> s) { 
		if (s.second.getTime() > lastAnalysis)
		{
			return true;}
		return false;});

	if (newSales)
	{
		return true;
	}
	return false;
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
