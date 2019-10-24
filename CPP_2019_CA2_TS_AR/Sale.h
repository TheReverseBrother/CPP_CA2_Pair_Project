#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Sale
{
private:
	int ID;
	string title;
	string color;
	string size;
	int quantity;
	float cost;

public:
	Sale();
	Sale(string title, string color, string size, int quantity, float cost);
	~Sale();

	void setTitle(string title);
	void setColor(string color);
	void setSize(string size);
	void setQuantity(int quantity);
	void setCost();

	int getID() const;
	string getTitle() const;
	string getColor() const;
	string getSize() const;
	int getQuantity() const;
	float getCost() const;

	bool operator==(Sale rhs);
	bool operator!=(Sale rhs);

	friend ofstream& operator<<(ofstream& os, Sale item);
	friend ifstream& operator>>(ifstream& in, Sale item);
	
};

