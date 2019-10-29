#pragma once
#include "pch.h"
#include <list>
class Sale
{
private:
	int ID;
	string salesAssistant;
	list<StockItem> items;
	static int salesCount;

public:
	Sale();
	Sale(int id, string salesAssistant, list<StockItem> items);
	~Sale();

	//Getters
	int getID();
	string getAssistant();
	list<StockItem> getItems();

	//Setters
	void setID(int ID);
	void setAssistant(string assistant);
	void setItems(list<StockItem> items);


};

