#include "StockItem.h"
int StockItem::stockItemCount = 100;

#pragma region Constructors
StockItem::StockItem()
{
	this->ID = 1;
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
#pragma endregion
#pragma region Setters
void StockItem::setID(int ID)
{
	this->ID = ID;
}

void StockItem::setTitle(string& title)
{
	if (title.size() < 4)
	{
		throw domain_error("Invalid Length of String");
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
#pragma endregion

#pragma region Getters
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
#pragma endregion

#pragma region Methods
void StockItem::print()
{
	printf("%-10d %-10s %-10s %-10s %-10d %-10f\n", this->ID, this->title.c_str(), this->color.c_str(), this->size.c_str(), this->quantity, this->cost);
}
#pragma endregion

#pragma region Operators
bool StockItem::operator==(const StockItem& rhs) const
{
	if ((this->ID == rhs.getID())&&(this->color == rhs.getColor())&&(this->title==rhs.getTitle())
		&&(this->cost==rhs.getCost())&&(this->size==rhs.getSize())&&(this->quantity==rhs.getQuantity()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool StockItem::operator!=(StockItem& rhs)
{
	return false;
}

ostream& operator<<(ostream& os, StockItem& item)
{
	os << item.getID() << "/" << item.getTitle() << "/" << item.getColor() << "/" << item.getSize() << "/" << 
		item.getQuantity() << "/" << item.getCost();
	return os;
}

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
#pragma endregion

#pragma region Static Methods
multiset<StockItem> StockItem::loadStock()
{
	ifstream in;
	ofstream out;
	multiset<StockItem> stock;

	in.open("stock-list.txt");

	string temp;
	string error;
	string delimiter = "/";
	string id;
	string title;
	string color;
	string size;
	string quantity;
	string cost;
	int ID;
	int Quantity;
	float Cost;

	if (in.fail())
	{
		cout << "error loading file" << endl;
		out.open("stock-list.txt");
		out.close();
		in.close();
		
	}

	while (!in.eof())
	{
		try
		{
		//cout << "test";
		in >> temp;
		error = temp;

		if (temp.length() > 10)
		{
			//splice string 

			id = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			title = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			color = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			size = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			quantity = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			cost = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			/// cast to correct types

			//id
			try
			{
				ID = stoi(id);
			}
			catch (invalid_argument const& e)
			{
				cout << "invalid argument while loading 'stock-list.txt' id on item " << error << endl;
			}
			catch (out_of_range const& e)
			{
				cout << "out of range error in 'stock-list.txt' id on item " << error << endl;
			}


			//quantity
			try
			{
				Quantity = stoi(quantity);
			}
			catch (invalid_argument const& e)
			{
				cout << "invalid argument while loading 'stock-list.txt' quantity on item " << error << endl;
			}
			catch (out_of_range const& e)
			{
				cout << "out of range error in 'stock-list.txt' quantity on item " << error << endl;
			}

			//cost
			try
			{
				Cost = stof(cost);
			}
			catch (invalid_argument const& e)
			{
				cout << "invalid argument while loading 'stock-list.txt' cost on item " << error << endl;
			}
			catch (out_of_range const& e)
			{
				cout << "out of range error in 'stock-list.txt' cost on item " << error << endl;
			}

			// create object and add to set

			//cout << "test2" << title << color << size << Quantity << Cost << endl;


			StockItem item(ID, title, color, size, Quantity, Cost);
			stock.insert(item);
		}
		
		}
		catch (domain_error e)
		{
			cout << "Error Loading StockItem: " << e.what() << endl;
		}
		catch (invalid_argument const& e)
		{
			cout << "invalid argument while loading 'stock-list.txt' "<<  endl;
		}
		catch (out_of_range const& e)
		{
			cout << "out of range error in 'stock-list.txt' cost on item "<< endl;
		}
	}
	in.close();
	return stock;
}

void StockItem::saveStock(const multiset<StockItem>& stock)
{
	ofstream out;
	out.open("stock-list.txt");

	for (auto x : stock)
	{
		StockItem item = (StockItem)x;
		out << item << endl;
	}

	out.close();
}
#pragma endregion
