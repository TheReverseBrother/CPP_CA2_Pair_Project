#pragma once
#include "pch.h"
#include <algorithm>
#include "StockItem.h"
class StockItem;
using namespace std;
class Sale
{
private:
	int ID;
	string salesAssistant;
	list<StockItem> items;
	time_t DOC;
	static int salesCount;

public:
	Sale();
	Sale(string salesAssistant, list<StockItem> items);
	~Sale();

	//Getters
	int getID()const;
	string getAssistant() const;
	list<StockItem> getItems()const;
	time_t getTime() const;

	//Setters
	void setID(int ID);
	void setAssistant(string assistant);
	void setItems(list<StockItem> items);
	void setTime(time_t DOC);

	bool removeItem(const StockItem& item);

	//Operators
	friend ostream& operator<<(ostream& os, const Sale& sale);
	friend istream& operator>>(istream& in, Sale& sale);
	bool operator< (const Sale& rhs) const;
	bool operator== (const Sale& rhs) const;


	static multiset<Sale> loadSales();
	static void saveSales(const multiset<Sale> Sales);
};

