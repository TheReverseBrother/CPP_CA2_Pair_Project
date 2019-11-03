#pragma once
#include "pch.h"

using namespace std;
class StockItem
{
private:
	int ID;
	string title;
	string color;
	string size;
	int quantity;
	float cost;

public:
	static int stockItemCount;

	StockItem();
	StockItem(int ID,string title, string color, string size, int quantity, float cost);
	StockItem(string title, string color, string size, int quantity, float cost);
	~StockItem();
	

	void setID(int ID);
	void setTitle(string& title);
	void setColor(string& color);
	void setSize(string& size);
	void setQuantity(int& quantity);
	void setCost(float& cost);

	int getID() const;
	string getTitle() const;
	string getColor() const;
	string getSize() const;
	int getQuantity() const;
	float getCost() const;

	bool operator==(StockItem& rhs);
	bool operator!=(StockItem& rhs);

	friend ostream& operator<<(ostream& os, StockItem& item);
	friend istream& operator>>(istream& in, StockItem& item);
	bool operator < (const StockItem& rhs) const;
};
