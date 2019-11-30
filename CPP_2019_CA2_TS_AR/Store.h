#include "pch.h"
#pragma once
class SalesAnalysis;
class Sale;
class Stockitem;
using namespace std;


class Store
{
private:
	map<int, StockItem> stock;
	map<int, Sale> sales;
	list<SalesAnalysis> analysisList;

public:
	Store();
	~Store();

	bool addStockItem(StockItem& item);
	bool addSale(Sale& sale);
	bool addAnalysis(SalesAnalysis& analysis);

	bool removeStockItem(int& ID);
	bool removeSale(int& ID);
	bool checkStockItemExists(int &ID);
	bool decrementStockQuantity(int &ID,int &Quantity);

	StockItem searchByID(int& ID);
	StockItem searchByPLACEHOLDER();
	StockItem searchByPLACEHOLDER2();

	map<int, StockItem>& getStock();
	map<int, Sale>& getSales();
	list<SalesAnalysis> getAnalysises();

	void SaveAll();
	void LoadAll();

};

