#include "pch.h"

class SalesAnalysis
{
private:
	int ID;
	time_t dayOfCreation, lastAnalysis;
	float totalValueOfSales;
	static int SalesCount;
public:
	SalesAnalysis();
	SalesAnalysis(int ID, time_t dayOfCreation, time_t lastAnalysis, float totalValueOfSales);
	SalesAnalysis(time_t lastAnalysis, float totalValueOfSales);
	~SalesAnalysis();

	time_t getDateOfCreation() const;
	time_t getlastAnalysis() const;
	float getTotalValue() const;

	void setID(int ID);
	void setLastAnalysis(time_t LA);
	void setDateOfCreation(time_t DOC);
	void setTotalValue(float value);

	friend ostream& operator<<(ostream& os, const SalesAnalysis& saleAnalysis);
	friend istream& operator>>(istream& in, const SalesAnalysis& saleAnalysis);


	static list<SalesAnalysis> loadAnalysises();
	static void saveAnalysises();

};
