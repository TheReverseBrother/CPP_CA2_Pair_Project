#include "StockItem.h"
int StockItem::stockItemCount = 100;
StockItem::StockItem()
{
	
	this->ID = stockItemCount + 1;
	this->title = "Jeans";
	this->color = "Blue";
	this->size = SIZE::M;
	this->quantity = 10;
	this->cost = 2.00;
	StockItem::stockItemCount++;
}

StockItem::StockItem(string title, string color, SIZE size, int quantity, float cost)
{
	this->ID = stockItemCount + 1;
	setTitle(title);
	setColor(color);
	setSize(size);
	setQuantity(quantity);
	setCost(cost);
}

StockItem::~StockItem()
{
}


//Setters
void StockItem::setTitle(string& title)
{
	if (title.size() < 4)
	{
		throw new domain_error("Invalid Length of String");
	}
	else
	{
		this->title = title;
	}
}

void StockItem::setColor(string& color)
{
	if (color.length() <3)
	{
		throw domain_error("Invalid Length of String");
	}
	else
	{
		this->color = color;
	}
}

void StockItem::setSize(SIZE& size)
{
	this->size = size;
}

void StockItem::setQuantity(int& quantity)
{
	if (quantity < 1)
	{
		throw domain_error("Invalid Number");
	}
	else
	{
		this->quantity = quantity;
	}
}

void StockItem::setCost(float& cost)
{
	if (cost <= 0.00)
	{
		throw domain_error("Invalid Number");
	}
	else
	{
		this->cost = cost;
	}
}


//Getters
int StockItem::getID() const
{
	return this->ID;
}

string StockItem::getTitle() const
{
	return this->title;
}

string StockItem::getColor() const
{
	return this->color;
}

SIZE StockItem::getSize() const
{
	return this->size;
}

int StockItem::getQuantity() const
{
	return this->quantity;
}

float StockItem::getCost() const
{
	return this->cost;
}

bool StockItem::operator==(StockItem& rhs)
{
	return false;
}

bool StockItem::operator!=(StockItem& rhs)
{
	return false;
}

ofstream& operator<<(ofstream& os, StockItem& item)
{
	os << item.getID() << item.getTitle() << item.getColor() << item.getQuantity() << item.getCost() << endl;
	return os;
}

//ifstream& operator>>(ifstream& in, StockItem& item)
//{
//	// TODO: insert return statement here
//}
