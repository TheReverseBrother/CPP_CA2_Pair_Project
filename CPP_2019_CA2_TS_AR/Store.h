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
	void printSales();
	void printStock();
	void printSales(map<int,Sale>& s);
	void printStock(map<int, StockItem>& s);

	map<int, StockItem>& getStock();
	map<int, Sale>& getSales();
	list<SalesAnalysis> getAnalysises();
	time_t getLastAnalysisDate();
	bool checkIfNewSales();

	void SaveAll();
	void LoadAll();

	void loadStaticValues()
	{
		ifstream in;
		in.open("IDs.txt");

		in >> StockItem::stockItemCount;
		in >> Sale::salesCount;
		in >> SalesAnalysis::SalesCount;
	}

	void saveStaticValues()
	{
		ofstream out;
		out.open("IDs.txt");

		out << StockItem::stockItemCount << endl;
		out << Sale::salesCount << endl;
		out << SalesAnalysis::SalesCount << endl;
	}

};

