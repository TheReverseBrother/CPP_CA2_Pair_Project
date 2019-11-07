#pragma once
#include "pch.h"
using namespace std;
class SalesAnalysis
{
private:
	int ID;
	time_t dayOfCreation;
	float totalValueOfSales;
	static int SalesCount;
public:
	SalesAnalysis();
	SalesAnalysis(int ID, time_t dayOfCreation,float totalValueOfSales);
	SalesAnalysis(float totalValueOfSales);
	~SalesAnalysis();

	int getID() const;
	time_t getDateOfCreation() const;
	float getTotalValue() const;

	void setID(int& ID);
	void setDateOfCreation(time_t& DOC);
	void setTotalValue(float& value);

	friend ostream& operator<<(ostream& os, SalesAnalysis& saleAnalysis);
	friend istream& operator>>(istream& in, SalesAnalysis& saleAnalysis);


	static list<SalesAnalysis> loadAnalysises();
	static void saveAnalysises(list<SalesAnalysis>& list);

};