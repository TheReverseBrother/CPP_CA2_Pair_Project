#include "pch.h"


// Method Definitions 
void loadStock();
void outputStock();

// Streams
ifstream in;
ofstream out;

//Stock set

multiset<StockItem> stock;
multiset<StockItem>::iterator stockBegin = stock.begin();
multiset<StockItem>::iterator stockEnd = stock.cend();




int main()
{
	loadStock();


    std::cout << "Hello World!\n";

	//StockItem Jeans;
	//cout << Jeans.getTitle() << endl;

	StockItem Jacket = StockItem("Jacket", "RED", "XL", 2, 50);
	StockItem jeans;
	cout<<"Jacket ID  "<<Jacket.getID()<<endl;
	cout << "Jean ID  " << jeans.getID() << endl;
	cout << endl;
	cout << "Stock Count: " << StockItem::stockItemCount << endl;
	cout << endl;

	cout << "All stock" << endl;
	for (StockItem s : stock)
	{
		cout << s << endl;
	}




	cout << stock.size() << endl;
	outputStock();
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
		loadStock();
	}

	while (!in.eof())
	{
		cout << "test";
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

			cout << "test2" << title << color << size << Quantity << Cost << endl;


			StockItem item(ID,title, color, size, Quantity, Cost);
			stock.insert(item);
			
		}
	}
}

	//todo read from file into set



void outputStock()
{
	out.open("stock-list.txt");
	stockBegin = stock.begin();

	for (auto x : stock)
	{
		StockItem item = (StockItem)x;
		out << item;
	}

	out.close();
}