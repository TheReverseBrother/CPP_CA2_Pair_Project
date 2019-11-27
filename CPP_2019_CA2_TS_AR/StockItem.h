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

#pragma region Constructors
	StockItem();
	StockItem(int ID,string title, string color, string size, int quantity, float cost);
	StockItem(string title, string color, string size, int quantity, float cost);
	~StockItem();
#pragma endregion 
	
#pragma region Setters
	void setID(int ID);
	void setTitle(string& title);
	void setColor(string& color);
	void setSize(string& size);
	void setQuantity(int& quantity);
	void setCost(float& cost);
#pragma endregion

#pragma region Getters
	int getID() const;
	string getTitle() const;
	string getColor() const;
	string getSize() const;
	int getQuantity() const;
	float getCost() const;
#pragma endregion

#pragma region Methods
	void print();
#pragma endregion

#pragma region Operators
	bool operator==(const StockItem& rhs)const;
	bool operator!=(StockItem& rhs);

	friend ostream& operator<<(ostream& os, StockItem& item);
	friend istream& operator>>(istream& in, StockItem& item);
	bool operator < (const StockItem& rhs) const;
#pragma endregion

#pragma region Static Methods
	static multiset<StockItem> loadStock();
	static void saveStock(const multiset<StockItem>& stock);
#pragma endregion
};

