#include "Sale.h"
int Sale::salesCount = 50;
Sale::Sale()
{

}

Sale::Sale(string salesAssistant, list<StockItem> items)
{
	setID(id);
	setAssistant(salesAssistant);
	setItems(items);
}

Sale::~Sale()
{
}

int Sale::getID()
{
	return 0;
}

string Sale::getAssistant()
{
	return string();
}

list<StockItem> Sale::getItems()
{
	return list<StockItem>();
}

void Sale::setID(int ID)
{
}

void Sale::setAssistant(string assistant)
{
}

void Sale::setItems(list<StockItem> items)
{
}
