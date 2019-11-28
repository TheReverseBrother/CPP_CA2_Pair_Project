#pragma once
#include "pch.h"
#include "Sale.h"
class Sale;
using namespace std;
class SalesAnalysis
{
private:
	int ID;
	time_t dayOfCreation;
	time_t lastAnalysis;
	float totalValueOfSales;
	static int SalesCount;
public:
#pragma region Constructors
	SalesAnalysis();
	SalesAnalysis(int ID, time_t dayOfCreation,float totalValueOfSales);
	SalesAnalysis(time_t lastAnalysis);
	~SalesAnalysis();
#pragma endregion

#pragma region Getters
	int getID() const;
	time_t getDateOfCreation() const;
	float getTotalValue() const;
	time_t getLastAnalysis() const;
#pragma endregion

#pragma region Setters
	void setID(int& ID);
	void setDateOfCreation(time_t& DOC);
	void setTotalValue(float& value);
	void setLastAnalysis(time_t& lastAnalysis);
#pragma endregion

#pragma region Methods
	void print();
#pragma endregion

#pragma region Operators
	friend ostream& operator<<(ostream& os, SalesAnalysis& saleAnalysis);
	friend istream& operator>>(istream& in, SalesAnalysis& saleAnalysis);
	void operator()(pair<int,Sale> x);
#pragma endregion

#pragma region Static Methods
	static list<SalesAnalysis> loadAnalysises();
	static void saveAnalysises(list<SalesAnalysis>& list);
#pragma endregion
};
