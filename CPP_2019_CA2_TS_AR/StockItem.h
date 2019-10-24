#pragma once
#include "pch.h"

using namespace std;
class StockItem
{
private:
	int ID;
	string title;
	string color;
	SIZE size;
	int quantity;
	float cost;
	static int stockItemCount;
public:
	StockItem();
	StockItem(string title, string color, SIZE size, int quantity, float cost);
	~StockItem();

	void setTitle(string& title);
	void setColor(string& color);
	void setSize(SIZE& size);
	void setQuantity(int& quantity);
	void setCost(float& cost);

	int getID() const;
	string getTitle() const;
	string getColor() const;
	SIZE getSize() const;
	int getQuantity() const;
	float getCost() const;

	bool operator==(StockItem& rhs);
	bool operator!=(StockItem& rhs);

	friend ofstream& operator<<(ofstream& os, StockItem& item);
	friend ifstream& operator>>(ifstream& in, StockItem& item);
	
};

