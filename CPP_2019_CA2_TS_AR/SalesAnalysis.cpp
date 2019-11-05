#include "SalesAnalysis.h"

int SalesAnalysis::SalesCount = 1661;

SalesAnalysis::SalesAnalysis()
{
	this->ID = 1;
	this->dayOfCreation = time(0);
	this->lastAnalysis = time(0);
	this->totalValueOfSales = 1.00;
}

SalesAnalysis::SalesAnalysis(int ID, time_t dayOfCreation, time_t lastAnalysis, float totalValueOfSales)
{
	setID(ID);
	setDateOfCreation(dayOfCreation);
	setLastAnalysis(lastAnalysis);
	setTotalValue(totalValueOfSales);
}

SalesAnalysis::SalesAnalysis(time_t lastAnalysis, float totalValueOfSales)
{
	++SalesAnalysis::SalesCount;
	setID(SalesAnalysis::SalesCount);
	this->dayOfCreation = time(0);
	setLastAnalysis(lastAnalysis);
	setTotalValue(totalValueOfSales);
}

SalesAnalysis::~SalesAnalysis()
{
}


//Getters
time_t SalesAnalysis::getDateOfCreation() const
{
	return this->dayOfCreation;
}

time_t SalesAnalysis::getlastAnalysis() const
{
	return this->lastAnalysis;
}

float SalesAnalysis::getTotalValue() const
{
	return this->totalValueOfSales;
}


//Setters
void SalesAnalysis::setID(int& ID)
{
	this->ID = ID;
}

void SalesAnalysis::setLastAnalysis(time_t& LA)
{
	this->lastAnalysis = LA;
}

void SalesAnalysis::setDateOfCreation(time_t& DOC)
{
	this->dayOfCreation = DOC;
}

void SalesAnalysis::setTotalValue(float& value)
{
	this->totalValueOfSales = value;
}

ostream& operator<<(ostream& os, const SalesAnalysis& saleAnalysis)
{
	// TODO: insert return statement here
}

istream& operator>>(istream& in, const SalesAnalysis& saleAnalysis)
{
	// TODO: insert return statement here
}

list<SalesAnalysis> SalesAnalysis::loadAnalysises()
{
	return list<SalesAnalysis>();
}

void SalesAnalysis::saveAnalysises()
{
}

