#include "StockItem.h"

int StockItem::stockItemCount = 100;

StockItem::StockItem()
{
	++StockItem::stockItemCount;
	this->ID = StockItem::stockItemCount;
	this->title = "Jeans";
	this->color = "Blue";
	this->size = "XL";
	this->quantity = 10;
	this->cost = 2.00;
	
}

StockItem::StockItem(int ID,string title, string color, string size, int quantity, float cost)
{
	setID(ID);
	setTitle(title);
	setColor(color);
	setSize(size);
	setQuantity(quantity);
	setCost(cost);
}

StockItem::StockItem(string title, string color, string size, int quantity, float cost)
{
	++StockItem::stockItemCount;
	this->ID = StockItem::stockItemCount;
	setTitle(title);
	setColor(color);
	setSize(size);
	setQuantity(quantity);
	setCost(cost);
}

StockItem::~StockItem()
{
	//stockItemCount = stockItemCount -1;
}


void StockItem::setID(int ID)
{
	this->ID = ID;
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

void StockItem::setSize(string& size)
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

string StockItem::getSize() const
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

ostream& operator<<(ostream& os, StockItem& item)
{
	os << item.getID() << "/" << item.getTitle() << "/" << item.getColor() << "/" << item.getSize() << "/" << 
		item.getQuantity() << "/" << item.getCost() << endl;
	return os;
}


// comparison operator for set
bool StockItem::operator < (const StockItem& rhs) const
{

	if (this->ID == rhs.getID()) { return true; }
	else { return false; }
	//return false;
}



istream& operator>>(istream& in, StockItem& item)
{
	int id,quantity;
	string title, color, size;
	float cost;

	in >> id;
	item.setID(id);

	in >> title;
	item.setTitle(title);

	in >> color;
	item.setColor(color);

	in >> size;
	item.setSize(size);

	in >> quantity;
	item.setQuantity(quantity);

	in >> cost;
	item.setCost(cost);

	return in;
}
