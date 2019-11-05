#include "SalesAnalysis.h"
#include <list>
int SalesAnalysis::SalesCount = 1661;

SalesAnalysis::SalesAnalysis()
{
	this->ID = 1;
	this->dayOfCreation = time(0);
	this->totalValueOfSales = 1.00;
}

SalesAnalysis::SalesAnalysis(int ID, time_t dayOfCreation, float totalValueOfSales)
{
	setID(ID);
	setDateOfCreation(dayOfCreation);
	
	setTotalValue(totalValueOfSales);
}

SalesAnalysis::SalesAnalysis(float totalValueOfSales)
{
	++SalesAnalysis::SalesCount;
	setID(SalesAnalysis::SalesCount);
	this->dayOfCreation = time(0);
	setTotalValue(totalValueOfSales);
}

SalesAnalysis::~SalesAnalysis()
{
}

//Getters
int SalesAnalysis::getID() const
{
	return this->ID;
}
time_t SalesAnalysis::getDateOfCreation() const
{
	return this->dayOfCreation;
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
	os << saleAnalysis.getID() << "/" << saleAnalysis.getDateOfCreation() << "/" <<  saleAnalysis.getTotalValue() << endl;

	return os;
}

istream& operator>>(istream& in,SalesAnalysis& saleAnalysis)
{
	int id,timeInt = 0;
	float price;
	time_t timeInfo;
	string data,info;
	string delimiter = "/";
	getline(in,data);
	if (data.empty())
	{
		return in;
	}
	try
	{
		info = data.substr(0, data.find(delimiter));
		data.erase(0, data.find(delimiter) + delimiter.length());
		id = stoi(info);
		saleAnalysis.setID(id);

		info = data.substr(0, data.find(delimiter));
		data.erase(0, data.find(delimiter) + delimiter.length());
		timeInt = stoi(info);
		timeInfo = (time_t) timeInt;
		saleAnalysis.setDateOfCreation(timeInfo);

		info = data.substr(0, data.find(delimiter));
		data.erase(0, data.find(delimiter) + delimiter.length());
	}
	catch (exception e)
	{
		e.what();
		int x = 0;
		saleAnalysis.setID(x);
	}

	return in;

}

list<SalesAnalysis> SalesAnalysis::loadAnalysises()
{
	list<SalesAnalysis> analysises;
	ifstream in;
	in.open("sales-analysis.txt");
	if (in.fail())
	{
		cout << "Failed To Load Sales Analysis" << endl;
	}
	else
	{
		while (!in.eof())
		{
			SalesAnalysis saleAnlysis;
			in >> saleAnlysis;
			if (saleAnlysis.getID() != 0)
			{
				analysises.push_back(saleAnlysis);
			}
		}
	}
	return analysises;
}

void SalesAnalysis::saveAnalysises(list<SalesAnalysis>& list)
{
	ofstream out;
	out.open("sales-analysis.txt");
	if (out.fail())
	{
		cout << "Error Saving SalesAnalysis" << endl;
		out.close();
	}
	else
	{

		for (SalesAnalysis s : list)
		{
			out << s << endl;
		}

	}
	out.close();
}

