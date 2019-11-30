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
	float totalSalePrice;
	time_t DOC;
public:
	static int salesCount;

#pragma region Constructors
	Sale();
	Sale(string salesAssistant, list<StockItem> items, float totalvalue);
	~Sale();
#pragma endregion

#pragma region Getters
	int getID()const;
	string getAssistant() const;
	list<StockItem> getItems()const;
	time_t getTime() const;
	float getTotalSalePrice() const;
#pragma endregion

#pragma region Setters
	void setID(int ID);
	void setAssistant(string assistant);
	void setItems(list<StockItem> items);
	void setTime(time_t DOC);
	void setTotalSalePrice(float price);
#pragma endregion

#pragma region Methods
	void print();
	bool removeItem(const StockItem& item);
#pragma endregion

#pragma region Operators
	friend ostream& operator<<(ostream& os, const Sale& sale);
	friend istream& operator>>(istream& in, Sale& sale);
	bool operator< (const Sale& rhs) const;
	bool operator== (const Sale& rhs) const;
#pragma endregion

#pragma region Static Methods
	static map<int, Sale> loadSales();
	static void saveSales(const map<int, Sale> Sales);
#pragma endregion
};

