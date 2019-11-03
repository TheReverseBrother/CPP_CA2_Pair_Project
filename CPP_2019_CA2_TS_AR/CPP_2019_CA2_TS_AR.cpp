#include "pch.h"


// Method Definitions 
void loadStock();
void outputStock();
void outputSales();
void loadSales();
bool removeStock(const StockItem& item);
// Streams
ifstream in;
ofstream out;

//Stock set

multiset<StockItem> stock;
multiset<Sale> Sales;
multiset<StockItem>::iterator stockBegin = stock.begin();
multiset<StockItem>::iterator stockEnd = stock.cend();




int main()
{
	loadStock();
	loadSales();

	cout << endl;
	cout << endl;
    std::cout << "Hello World!\n";

	//StockItem Jeans;
	//cout << Jeans.getTitle() << endl;
	StockItem vanns(152, "VANNNS", "BLUE", "XL", 2, 50);
	StockItem Jacket = StockItem("Jacket", "RED", "XL", 2, 50);
	StockItem shoe(1, "Jacket", "RED", "XL", 2, 50);
	StockItem shoes(1, "Jacket", "RED", "XL", 2, 50);
	StockItem jeans;
	cout<<"Jacket ID  "<<Jacket.getID()<<endl;
	cout << "Jean ID  " << jeans.getID() << endl;
	list<StockItem> itemList;
	itemList.push_back(shoe);
	itemList.push_back(shoes);
	Sale sale1("George",itemList);
	if (removeStock(vanns))
	{
		cout << "Hi Boi" << endl;
	}
	stock.insert(vanns);
	for (StockItem s : stock)
	{
		cout << s << endl;
	}

	for (Sale s : Sales)
	{
		cout << s << endl;
	}

	
	outputStock();
	outputSales();
}

bool removeStock(const StockItem& item)
{
	auto it = find(stock.begin(), stock.end(), item);
	if (it != stock.end())
	{
		stock.erase(it);
		return true;
	}
	return false;
}
void loadStock()
{
	in.open("stock-list.txt");

	string temp;
	string error;
	string delimiter = "/";
	string id;
	string title;
	string color;
	string size;
	string quantity;
	string cost;
	int ID;
	int Quantity;
	float Cost;

	if (in.fail())
	{
		cout << "error loading file" << endl;
		out.open("stock-list.txt");
		out.close();
		in.close();
		loadStock();
	}

	while (!in.eof())
	{
		//cout << "test";
		in >> temp;
		error = temp;

		if (temp.length() > 10) 
		{
			//splice string 

			id = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			title = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			color = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			size = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			quantity = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			cost = temp.substr(0, temp.find(delimiter));
			temp.erase(0, temp.find(delimiter) + delimiter.length());

			/// cast to correct types

			//id
			try
			{
				ID = stoi(id);
			}
			catch (invalid_argument const& e)
			{
				cout << "invalid argument while loading 'stock-list.txt' id on item " << error << endl;
			}
			catch (out_of_range const& e)
			{
				cout << "out of range error in 'stock-list.txt' id on item " << error << endl;
			}


			//quantity
			try
			{
				Quantity = stoi(quantity);
			}
			catch (invalid_argument const& e)
			{
				cout << "invalid argument while loading 'stock-list.txt' quantity on item " << error << endl;
			}
			catch (out_of_range const& e)
			{
				cout << "out of range error in 'stock-list.txt' quantity on item " << error << endl;
			}

			//cost
			try
			{
				Cost = stof(cost);
			}
			catch (invalid_argument const& e)
			{
				cout << "invalid argument while loading 'stock-list.txt' cost on item " << error << endl;
			}
			catch (out_of_range const& e)
			{
				cout << "out of range error in 'stock-list.txt' cost on item " << error << endl;
			}

			// create object and add to set

			//cout << "test2" << title << color << size << Quantity << Cost << endl;


			StockItem item(ID,title, color, size, Quantity, Cost);
			stock.insert(item);
			
		}
	}
	in.close();
}

void outputStock()
{
	out.open("stock-list.txt");
	stockBegin = stock.begin();

	for (auto x : stock)
	{
		StockItem item = (StockItem)x;
		out << item << endl;
	}

	out.close();
}

void loadSales()
{
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
			if (!in.eof())
			{
				Sales.insert(blankSale);
			}
		}
		/*while (!in.eof())
		{
			Sale blankSale;
			in >> blankSale;
			Sales.insert(blankSale);
			
		}*/
	}
	in.close();
}

void outputSales()
{
	out.open("sales.txt");
	if (out.fail())
	{
		cout << "Error Saving Sales" << endl;
		out.close();
	}
	else
	{

		for (Sale s: Sales)
		{
			out << s << endl;
		}

	}
	out.close();
}