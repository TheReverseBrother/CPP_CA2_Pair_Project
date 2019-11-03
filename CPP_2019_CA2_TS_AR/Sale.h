#pragma once
#include "pch.h"
#include "StockItem.h"
class StockItem;
using namespace std;
class Sale
{
private:
	int ID;
	string salesAssistant;
	list<StockItem> items;
	static int salesCount;

public:
	Sale();
	Sale(string salesAssistant, list<StockItem> items);
	~Sale();

	//Getters
	int getID()const;
	string getAssistant() const;
	list<StockItem> getItems()const;

	//Setters
	void setID(int ID);
	void setAssistant(string assistant);
	void setItems(list<StockItem> items);

	//Operators
	friend ostream& operator<<(ostream& os, const Sale& sale);
	friend istream& operator>>(istream& in, Sale& sale);
	bool operator< (const Sale& rhs) const;
};
