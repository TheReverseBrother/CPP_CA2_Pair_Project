#include "Sale.h"
int Sale::salesCount = 50;

#pragma region Constructors
Sale::Sale()
{
	//salesCount++;
	setID(1);
	this->DOC = time(0);
	this->totalSalePrice = 1;
	setAssistant("George Default");
	//setItems();
}

Sale::Sale(string salesAssistant, list<StockItem> items)
{
	salesCount++;
	setID(salesCount);
	setAssistant(salesAssistant);
	setItems(items);
}

Sale::~Sale()
{
}

#pragma endregion

#pragma region Getters
int Sale::getID() const 
{
	return this->ID;
}
string Sale::getAssistant() const 
{
	return this->salesAssistant;
}
list<StockItem> Sale::getItems() const 
{
	return this->items;
}
time_t Sale::getTime() const
{
	return this->DOC;
}
float Sale::getTotalSalePrice() const
{
	return this->totalSalePrice;
}
#pragma endregion

#pragma region Setters
void Sale::setID(int ID)
{
	this->ID = ID;
}
void Sale::setAssistant(string assistant)
{
	if (assistant.length() <4)
	{
		throw domain_error("Not Valid Length");
	}
	else
	{
		this->salesAssistant = assistant;
	}
}
void Sale::setItems(list<StockItem> items)
{
	if (items.size() <1)
	{
		throw domain_error("Need More Items");
	}
	else
	{
		this->items = items;
	}
}
void Sale::setTime(time_t DOC)
{
	this->DOC = DOC;
}
void Sale::setTotalSalePrice(float price)
{
	this->totalSalePrice = price;
}
#pragma endregion

#pragma region Methods
void Sale::print()
{
	string date = time_to_local_date(this->DOC);
	printf("%-10d %-20s %-10d %-15f %-15s\n", this->ID, this->salesAssistant.c_str(), this->items.size(), this->totalSalePrice, date.c_str());
}

bool Sale::removeItem(const StockItem& item)
{
	auto it = find(this->items.begin(),this->items.end(),item);
	if (it != items.end())
	{
		items.remove(item);
		return true;
	}
	return false;
}
#pragma endregion

#pragma region operators
ostream& operator<<(ostream& os, const Sale& sale)
{
	list<StockItem> items = sale.getItems();
	os << sale.getID() << "%/%" << sale.getAssistant() << "%/%" << sale.getTime() << "%/%" << sale.getTotalSalePrice() << "%/%";
	for (StockItem s : items)
	{
		os << s << "/%/";
	}

	return os;
}

istream& operator>>(istream& in, Sale& sale)
{
	list<StockItem> itemList;
	string data,info,id,title,color,size,quantity,cost;
	float costFloat,price = 0;
	int saleID,stockID,quantityInt,timeInt;
	time_t timeInfo;
	//Delimiters
	string infoDelimiter = "%/%";
	string itemDelimiter = "/%/";
	string delimiter = "/";

	//fetch Data
	std::getline(in, data);
	if (data.empty())
	{
		return in;
	}

	try
	{

		//Get Sale ID
		info = data.substr(0, data.find(infoDelimiter));
		data.erase(0, data.find(infoDelimiter) + infoDelimiter.length());
		saleID = stoi(info);

		//get Assistant
		info = data.substr(0, data.find(infoDelimiter));
		data.erase(0, data.find(infoDelimiter) + infoDelimiter.length());
		string assistant = info;

		//getDOC
		info = data.substr(0, data.find(infoDelimiter));
		data.erase(0, data.find(infoDelimiter) + infoDelimiter.length());
		timeInt = stoi(info);
		timeInfo = (time_t)timeInt;

		//getTotalPrice
		info = data.substr(0, data.find(infoDelimiter));
		data.erase(0, data.find(infoDelimiter) + infoDelimiter.length());
		price = stof(info);

		//fetch all stockitems
		size_t pos = 0;
		while ((pos = data.find(itemDelimiter)) != std::string::npos)
		{
			//gets Item string
			info = data.substr(0, pos);
			data.erase(0, pos + itemDelimiter.length());

			id = info.substr(0, info.find(delimiter));
			info.erase(0, info.find(delimiter) + delimiter.length());

			title = info.substr(0, info.find(delimiter));
			info.erase(0, info.find(delimiter) + delimiter.length());

			color = info.substr(0, info.find(delimiter));
			info.erase(0, info.find(delimiter) + delimiter.length());

			size = info.substr(0, info.find(delimiter));
			info.erase(0, info.find(delimiter) + delimiter.length());

			quantity = info.substr(0, info.find(delimiter));
			info.erase(0, info.find(delimiter) + delimiter.length());

			cost = info.substr(0, info.find(delimiter));
			info.erase(0, info.find(delimiter) + delimiter.length());

			
			stockID = stoi(id);

			//quantity
			quantityInt = stoi(quantity);

			//cost
			costFloat = stof(cost);

			StockItem item(stockID, title, color, size, quantityInt, costFloat);
			itemList.push_back(item);
		}

		sale.setAssistant(assistant);
		sale.setID(saleID);
		sale.setTime(timeInfo);
		sale.setItems(itemList);
		sale.setTotalSalePrice(price);
	}
	catch (domain_error e)
	{
		cout << "Error Loadin Sales: " << e.what() << endl;
		sale.setID(1);
	}
	catch (invalid_argument const& e)
	{
		cout << "Error Loading Sales: Invalid Arguement" << endl;
		sale.setID(1);
	}
	catch (out_of_range const& e)
	{
		cout << "Error Loading Sales: out of range " << endl;
		sale.setID(1);
	}


	return in;
}

bool Sale::operator< (const Sale& rhs) const
{

	if (this->ID == rhs.getID()) { return true; }
	else { return false; }
	//return false;
}

bool Sale::operator==(const Sale& rhs) const
{
	if (this->ID == rhs.getID() && this->salesAssistant == rhs.getAssistant() && this->items == rhs.getItems() )
	{
		return true;
	}
	return false;
}
#pragma endregion

#pragma region Static Methods
map<int,Sale> Sale::loadSales()
{
	ifstream in;
	map<int, Sale> Sales;
	in.open("sales.txt");
	if (in.fail())
	{
		cout << "Error Loadng Sales" << endl;
		in.close();
	}
	else
	{
		Sale blankSale;
		while (in >> blankSale)
		{
			if (!in.eof() && blankSale.getID() != 1)
			{
				Sales.insert(make_pair(blankSale.getID(), blankSale));
			}
		}
	}
	in.close();
	return Sales;
}

void Sale::saveSales(const map<int,Sale> Sales)
{
	ofstream out;
	out.open("sales.txt");
	if (out.fail())
	{
		cout << "Error Saving Sales" << endl;
		out.close();
	}
	else
	{

		for (auto i : Sales)
		{
			out << i.second << endl;
		}

	}
	out.close();

}
#pragma endregion