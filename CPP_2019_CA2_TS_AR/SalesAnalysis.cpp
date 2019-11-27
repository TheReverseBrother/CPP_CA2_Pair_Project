#include "SalesAnalysis.h"

int SalesAnalysis::SalesCount = 1661;
#pragma region Constructors
SalesAnalysis::SalesAnalysis()
{
	this->ID = 0;
	this->dayOfCreation = time(0);
	this->lastAnalysis = time(0);
	this->totalValueOfSales = 1.00;
}

SalesAnalysis::SalesAnalysis(int ID, time_t dayOfCreation, float totalValueOfSales)
{
	setID(ID);
	setDateOfCreation(dayOfCreation);
	
	setTotalValue(totalValueOfSales);
}

SalesAnalysis::SalesAnalysis(time_t lastAnalysis)
{
	++SalesAnalysis::SalesCount;
	setID(SalesAnalysis::SalesCount);
	this->dayOfCreation = time(0);
	this->lastAnalysis = lastAnalysis;
	this->totalValueOfSales = 0;
}

SalesAnalysis::~SalesAnalysis()
{
}
#pragma endregion

#pragma region Getters
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
time_t SalesAnalysis::getLastAnalysis() const
{
	return this->lastAnalysis;
}
#pragma endregion

#pragma region Setters
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

void SalesAnalysis::setLastAnalysis(time_t& lastAnalysis)
{
	this->lastAnalysis = lastAnalysis;
}
#pragma endregion

#pragma region Methods
void SalesAnalysis::print()
{
	string lastAnalysis = time_to_local_date(this->lastAnalysis);
	string date = time_to_local_date(this->dayOfCreation);
	printf("%-15d %-20s %-15f %-15s\n", this->ID, lastAnalysis.c_str(), this->totalValueOfSales, date.c_str());
}
#pragma endregion

#pragma region Operators
ostream& operator<<(ostream& os, SalesAnalysis& saleAnalysis)
{
	os << saleAnalysis.getID() << "/" << saleAnalysis.getDateOfCreation() << "/" << saleAnalysis.getLastAnalysis() << "/" <<   saleAnalysis.getTotalValue() << endl;

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
		timeInt = stoi(info);
		timeInfo = (time_t)timeInt;
		saleAnalysis.setLastAnalysis(timeInfo);

		info = data.substr(0, data.find(delimiter));
		data.erase(0, data.find(delimiter) + delimiter.length());
		price = stof(info);
		saleAnalysis.setTotalValue(price);
	}
	catch (domain_error e)
	{
		cout << "Error Loading SalesAnalysis" << endl;
		int x = 0;
		saleAnalysis.setID(x);
	}
	catch (invalid_argument const& e)
	{
		cout << "Error Loading SalesAnalysis" << endl;
		int x = 0;
		saleAnalysis.setID(x);
	}
	catch (out_of_range const& e)
	{
		cout << "Error Loading SalesAnalysis" << endl;
		int x = 0;
		saleAnalysis.setID(x);
	}

	return in;

}

void SalesAnalysis::operator()(Sale s)
{
	if (s.getTime() > this->lastAnalysis)
	{
		totalValueOfSales += s.getTotalSalePrice();
		s.print();
	}
}
#pragma endregion

#pragma region Static Methods
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
			out << s;
		}

	}
	out.close();
}
#pragma endregion
