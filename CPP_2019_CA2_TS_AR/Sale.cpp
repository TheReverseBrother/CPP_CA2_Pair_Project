#include "Sale.h"
int Sale::salesCount = 50;
Sale::Sale()
{
	salesCount++;
	setID(salesCount);
	setAssistant("George Default");
	//setItems();
}

Sale::Sale(string salesAssistant, list<StockItem> items)
{
	salesCount++;
	setID(salesCount);
	setAssistant(salesAssistant);
	setItems(items);
}

Sale::~Sale()
{
}

//Getters
int Sale::getID() const 
{
	return this->ID;
}
string Sale::getAssistant() const 
{
	return string();
}
list<StockItem> Sale::getItems() const 
{
	return list<StockItem>();
}


void Sale::setID(int ID)
{
	this->ID = ID;
}
void Sale::setAssistant(string assistant)
{
	if (assistant.length() <4)
	{
		throw domain_error("Not Valid Length");
	}
	else
	{
		this->salesAssistant = assistant;
	}
}
void Sale::setItems(list<StockItem> items)
{
	if (items.size() <1)
	{
		throw domain_error("Need More Items");
	}
	else
	{
		this->items = items;
	}
}

ostream& operator<<(ostream& os, const Sale& sale)
{
	return os;
}

istream& operator>>(istream& in, Sale& sale)
{
	return in;
}
