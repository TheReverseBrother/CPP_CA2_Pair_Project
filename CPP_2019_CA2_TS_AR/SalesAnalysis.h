#pragma once
#include "pch.h"
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
	SalesAnalysis();
	SalesAnalysis(int ID, time_t dayOfCreation,float totalValueOfSales);
	SalesAnalysis(time_t lastAnalysis);
	~SalesAnalysis();

	int getID() const;
	time_t getDateOfCreation() const;
	float getTotalValue() const;
	time_t getLastAnalysis() const;

	void setID(int& ID);
	void setDateOfCreation(time_t& DOC);
	void setTotalValue(float& value);
	void setLastAnalysis(time_t& lastAnalysis);

	friend ostream& operator<<(ostream& os, SalesAnalysis& saleAnalysis);
	friend istream& operator>>(istream& in, SalesAnalysis& saleAnalysis);


	static list<SalesAnalysis> loadAnalysises();
	static void saveAnalysises(list<SalesAnalysis>& list);

};
