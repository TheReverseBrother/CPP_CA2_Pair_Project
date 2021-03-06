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

	cout << "Succesfully added sale" << endl;
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

/*
Author Tomas
Used to check if an item exists by an ID
*/
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

/*
Author Tomas
Used to decrement a stock Item quantity once a sale occurs will not allow decrement below 0
*/
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

/*
Author Tomas
Simple Search Item (Better One in User Interface)
*/
StockItem Store::searchByID(int& ID)
{

	return stock.find(ID)->second;
}


/*
Give pointer to stock Map
*/
map<int, StockItem> *Store::getStock()
{
	map<int, StockItem> *pStock = &stock;
	return pStock;
}

/*
Returns reference to Sales Map
*/
map<int, Sale> &Store::getSales()
{
	return sales;
}


/*
Gets All Sale Analysis'
*/
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

 /*
 Author Tomas
 Gets the last Analysis Date
 */
 time_t Store::getLastAnalysisDate()
 {
	 SalesAnalysis s = *analysisList.rbegin();
	 time_t lastAnalysis = s.getDateOfCreation();
	 return lastAnalysis;
 }

 /*
	Author Tomas
	Checks the last Analysis date to the Sale Date and if sale happens after last analysis it returns true
 */
 bool Store::checkIfNewSales()
 {
	 time_t lastAnalysis = getLastAnalysisDate();

	 bool newSales = any_of(sales.begin(), sales.end(), [lastAnalysis](pair<int, Sale> s) {
		 if (s.second.getTime() > lastAnalysis)
		 {
			 return true;
		 }
		 return false; });

	 if (newSales)
	 {
		 return true;
	 }
	 return false;
 }

 /*
 Creates Sale Analysis if a new Sale had occured uses a functor to iterate through all Sales and add up final Price
 */
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

 /*
 Author Tomas
 Used to print all sales
 */
 void Store::printSales()
 {
	 printf("%-10s %-20s %-10s %-15s %-15s\n", "ID", "Assistant", "No. Items", "Total Price", "Date");
	 for (pair<int, Sale> i : this->sales)
	 {
		 i.second.print();
	 }
 }

 /*
 Author Tomas
 Used to print all Stock
 */
 void Store::printStock()
 {
	 printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "ID", "Item", "Color", "Size", "Quantity", "Unit Price");
	 for (pair<int, StockItem> i : this->stock)
	 {
		 i.second.print();
	 }
 }

 /*
 Author Tomas
 Used to print a select amount of sales
 */
 void Store::printSales(map<int, Sale>& s)
 {
	 printf("%-10s %-20s %-10s %-15s %-15s\n", "ID", "Assistant", "No. Items", "Total Price", "Date");
	 for (pair<int, Sale> x : s)
	 {
		 x.second.print();
	 }
 }

 /*
 Author Tomas
 Used to print select amount of stock
 */
 void Store::printStock(map<int, StockItem>& s)
 {
	 printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "ID", "Item", "Color", "Size", "Quantity", "Unit Price");
	 for (pair<int, StockItem> i : s)
	 {
		 i.second.print();
	 }
 }

void Store::LoadAll()
{

}
