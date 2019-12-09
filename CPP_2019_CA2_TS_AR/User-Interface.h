#pragma once
#include "pch.h"
#include <functional>
#include<vector>
#include<algorithm>


#pragma region Definitions
Store store;
map<int, StockItem> *stock = store.getStock();
map<int, Sale> sales = store.getSales();
list<SalesAnalysis> analysisList = store.getAnalysises();

#pragma endregion


#pragma region method definitions
void addStockMenu();
void modifyStockMenu();
void createSale();
void addSaleMenu();
void analyseSalesMenu();
void searchStockMenu();
void removeItemMenu();
void addNewStockItem();
void addNewSale();
void ModifyStock(StockItem &item);
inline int intValidator();
inline float floatValidator();
int mainMenuOptionCast(string input);
int addStockMenuCast(string input);
void createAnalysis();
bool removeStock(const int key);
bool removeSale(const int key);
void quitApplocation();
#pragma endregion


void printStockVector(vector<StockItem> vec)
{

	if (vec.size() < 1) { cout << "No Results Found" << endl; }
	else
	{
		cout << "Results" << endl << endl;
		printf("%-10s %-12s %-12s %-12s %-12s %-12s\n", "ID", "|Item", "|Color", "|Size", "|Quantity", "|Unit Price");
		
		
		cout << string(75, '-') << endl;

		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			/*cout << "ID: " << (*it).getID() << "| Title: " << (*it).getTitle() << "| Color: " << (*it).getColor() << "| Size: " << (*it).getSize()
				<< "| Quantity: " << (*it).getQuantity() << "| Cost: " << (*it).getCost() << endl;*/
			(*it).print();

		}
		cout << endl;
	}
}


//
/*
Authour: Aaron
Searchs the stock for results based on pFunc passed
*/ 
vector<StockItem> searchStockBy(function<bool(StockItem)> Pfunc, map<int, StockItem>& stock)
{
	vector<StockItem> results = {};
	StockItem temp;
	bool test;

	
		for (auto item : stock)
		{
			test = Pfunc(stock.at(item.second.getID()));
			if (test)
			{
				auto item2 = stock.at(item.second.getID());

				results.push_back(stock.at(item2.getID()));
			}
		}
	
	return results;

}

#pragma region enums
	enum mainMenuSelection
	{
		error = -1,
		addStock = 1,
		addSale = 2,
		analyseSales = 3,
		searchStock = 4,
		removeItem = 5,
		quit = 6
	};

	enum stockMenuEnums
	{
		newItem = 1,
		modifyStock = 2,
		back = 3,
	};

	enum salesMenuEnums
	{
		newSale = 1,
		Salesback = 2,

	};
#pragma endregion

#pragma region mainMenu


/*
Authour: Aaron
main menu accepts typed commands or numbers for input
*/
	void mainMenu()
	{
		int option;
		string input;
		bool selected = false;

		while (!selected)
		{
			cout << endl;
			cout << "---Main Menu---" << endl << endl;
			cout << "1: Add Stock" << endl;
			cout << "2: Add Sale" << endl;
			cout << "3: Analyse Sales" << endl;
			cout << "4: Search Stock" << endl;
			cout << "5: Remove Item" << endl;
			cout << "6: Quit" << endl;
			getline(cin, input);

			option = mainMenuOptionCast(input);

			switch (option)
			{
			case addStock: {selected = true; addStockMenu(); }
			case addSale: {selected = true; addSaleMenu(); }
			case analyseSales: {selected = true; analyseSalesMenu(); }
			case searchStock: {selected = true; searchStockMenu(); }
			case removeItem: {selected = true; removeItemMenu(); }
			case quit: {selected = true; quitApplocation(); }
			case error: {selected = true;  cout << "Error Returning to main menu" << endl; cout << endl; mainMenu(); }
			}
		}
	}

/*
Authour: Aaron
main menu casts comman inputs to numbers for switch case
*/
	int mainMenuOptionCast(string input)
	{
		int option = -1;

#pragma region regexExpressions
		smatch matches;

		regex addStockReg("[aA][dD]{2}.?[sS][tT][oO][cC][kK]");
		regex addSaleReg("[aA][dD]{2}.?[sS][tT][oO][cC][kK]");
		regex analyseSalesReg("[aA][nN][aA][lL][yY][sS][eE].?[sS][aA][Ll][eE][sS]?");
		regex searchStockReg("[sS][eE][aA][rR][cC][hH].?[sS][tT][oO][cC][kK]");
		regex removeItemReg("[rR][eE][mM][oO][vV][eE].?[iI][tT][eE][mM][sS]?");
		regex quitReg("[qQ][uU][iI][tT]");

#pragma endregion


		string temp = input.substr(0, input.find(" "));

		if (temp.length() == 1)
		{
			try
			{
				option = stoi(temp);
				return option;
			}
			catch (invalid_argument & e)
			{
				cout << "invaild Menu Selection in Main Menu" << endl; cout << endl;
				return option = -1;
			}
		}
		else
		{

			if (input.length() > 0)
			{
				if (regex_search(input, matches, addStockReg)) { return addStock; }
				else if (regex_search(input, matches, addSaleReg)) { return addSale; }
				else if (regex_search(input, matches, analyseSalesReg)) { return analyseSales; }
				else if (regex_search(input, matches, searchStockReg)) { return searchStock; }
				else if (regex_search(input, matches, removeItemReg)) { return removeItem; }
				else if (regex_search(input, matches, quitReg)) { return quit; }
			}
			else { return -1; }
		}
		return option;
	}

#pragma endregion

#pragma region Stock Menus

#pragma region addStockMenu
	void addStockMenu()
	{
		bool selected = false;
		int option = -1;
		string input;


		while (!selected)
		{
			cout << endl;
			cout << "---Stock Menu---" << endl << endl;
			cout << "1: New Item" << endl;
			cout << "2: Modify Stock" << endl;
			cout << "3: Back" << endl;
	
			getline(cin, input);
			cout << endl;
			option = addStockMenuCast(input);


			switch (option)
			{
			case newItem: {selected = true; addNewStockItem(); }
			case modifyStock: {selected = true; modifyStockMenu(); }
			case back: {selected = true; mainMenu();}
			case error: {cout << "Error Returning to main menu" << endl; mainMenu(); }
			}

		}


	}
#pragma endregion

#pragma region addStockMenuCast
	int addStockMenuCast(string input)
	{

#pragma region regexExpressions
		smatch matches;

		regex newItemReg("[nN][eE][wW].?[iI][tT][eE][mM]");
		regex modifyStockReg("[mM][oO][dD][iI][fF][yY].?[sS][tT][oO][cC][kK]");
		regex backReg("[bB][aA][cC][kK]");

#pragma endregion


		int option = -1;


		string temp = input.substr(0, input.find(" "));

		if (temp.length() == 1)
		{
			try
			{
				option = stoi(temp);
				return option;
			}
			catch (invalid_argument & e)
			{
				cout << "invaild Menu Selection in Main Menu" << endl;
				return option = -1;
			}
		}
		else
		{

			if (input.length() > 0)
			{
				if (regex_search(input, matches, newItemReg)) { return newItem; }
				else if (regex_search(input, matches, modifyStockReg)) { return modifyStock; }
				else if (regex_search(input, matches, backReg)) { return back; }
			}
			else { return -1; }
		}
		return option;

	}
#pragma endregion

#pragma region addNewStockItem
	/*
Authour: Aaron
has some built in validation for creating new stock items
*/
	void addNewStockItem()
	{
		bool selected = false;
		string input;
		string title;
		string color;
		string size;
		int quantity;
		float cost;

		while (!selected)
		{

			while (!selected)
			{
				cout << "please enter stock Item Title" << endl;
				getline(cin, title);
				transform(title.begin(), title.end(), title.begin(), ::toupper);
				selected = true;
			}

			selected = false;

			while (!selected)
			{
				cout << "please enter stock Item Color" << endl;
				getline(cin, color);
				transform(color.begin(), color.end(), color.begin(), ::toupper);
				selected = true;
			}
			selected = false;

			while (!selected)
			{
				cout << endl;
				cout << "Please Select new Size" << endl;
				input = "";
				cout << "1: XS" << endl;
				cout << "2: S" << endl;
				cout << "3: M" << endl;
				cout << "4: L" << endl;
				cout << "5: XL" << endl;
				getline(cin, input);

				if (input != "")
				{
					if (input == "1" || input == "XS" || input == "xs")
					{
						size = "XS";
						selected = true;
					}
					else if (input == "2" || input == "S" || input == "s")
					{
						size = "S";
						selected = true;
					}
					else if (input == "3" || input == "M" || input == "m")
					{
						size = "M";
						selected = true;
					}
					else if (input == "4" || input == "L" || input == "l")
					{
						size = "L";
						selected = true;
					}
					else if (input == "5" || input == "XL" || input == "xl")
					{
						size = "XL";

						selected = true;
					}
					else
					{
						cout << "Invalid Input" << endl;
					}
				}
			}

			selected = false;

			while (!selected)
			{
				cout << "please enter stock Item Quantity" << endl;
				getline(cin, input);
				quantity = stoi(input);

				selected = true;
			}

			selected = false;

			while (!selected)
			{
				cout << "please enter stock Item Cost" << endl;
				getline(cin, input);
				cost = stod(input);
				selected = true;
			}
			
			map<int, StockItem>::iterator it = (*stock).end();
			it--;
			StockItem item(title, color, size, quantity, cost);
			item.setID(it->second.getID() + 1);


			(*stock).insert(make_pair(item.getID(), item));

			cout << "Successfuly Created: " << item <<endl;

		}

		addStockMenu();
	}
#pragma endregion

#pragma region modifyStockMenu
	/*
Authour: Aaron
calls a search funtion that returns one stock item which then calls modify stock
*/
	void modifyStockMenu()
	{
		bool selected = false;
		smatch matches;
		string IDinput;
		regex IDReg("^[0-9]+$");
		vector<StockItem> results = {};
		StockItem item;

		while (!selected)
		{
			cout << endl;
			cout << "---Modify Stock---" << endl << endl;
			cout << "enter any letter to return to Stock menu" << endl << endl;
			cout << "Enter Stock ID" << endl;
			getline(cin, IDinput);

			if (regex_search(IDinput, matches, IDReg))
			{
				try
				{

					int ID = stoi(IDinput);

					function <bool(StockItem)> pFunc = [&ID](StockItem item)
					{
						if (item.getID() == ID) { return true; }
						else
						{
							return false;
						}
					};

					results = searchStockBy(pFunc, (*stock));

					if (results.size() == 1)
					{
						selected = true;
						for (vector<StockItem>::iterator It = results.begin(); It != results.end(); It++)
						{
							item = (*It);
							cout << "Result: " << item << endl;
						}
						ModifyStock((*stock).at(item.getID()));
					}

				}
				catch (invalid_argument & e)
				{
					cout << "Invalid Argument" << endl;
				}
			}
			else
			{
				selected = true;
				addStockMenu();

			}
		}
	}
#pragma endregion



#pragma region modifyStock

	/*
Authour: Aaron
a menu that allows the user to modify a selected stock item
*/
	void ModifyStock(StockItem &item)
	{

		bool selected = false;
		smatch matches;
		string input;
		regex TitleReg("[Tt][Ii][Tt][Ll][Ee]$");
		regex ColorReg("[Cc][Oo][Ll][Oo][Rr]$");
		regex SizeReg("[Ss][Ii][Zz][Ee]$");
		regex QuanityReg("[Qq][Uu][Aa][Nn][Ii][Tt][Yy]$");
		regex PriceReg("[Pp][Rr][Ii][Cc][Ee]$");
		regex BackReg("[Bb][Aa][Cc][Kk]$");
		int newValue;
		float newPrice;



		while (!selected)
		{
			cout << endl;
			cout << "---Modify Stock---" << endl << endl;
			cout << "Item to Modify: " << item << endl << endl;
			cout << "1: Title" << endl;
			cout << "2: Color" << endl;
			cout << "3: Size" << endl;
			cout << "4: Quanity" << endl;
			cout << "5: Price" << endl;
			cout << "6: Back" << endl;
			cout << endl;
			getline(cin, input);

			if (regex_search(input, matches, TitleReg) || input == "1")
			{
				while (!selected)
				{
					cout << "Please enter new Title" << endl;
					input = "";
					getline(cin, input);

					if (input != "")
					{
						try
						{
							(*stock).at(item.getID()).setTitle(input);
							/*item.setTitle(input);*/
							cout << "Successfully Changed Item Title" << endl;
							selected = true;
						}
						catch (domain_error e) { cout << "Invalid Length of String" << endl; }
					}
				}
				selected = false;
			}
			else if (regex_search(input, matches, ColorReg) || input == "2")
			{
				while (!selected)
				{
					cout << "Please enter new Color" << endl;
					input = "";
					getline(cin, input);

					if (input != "")
					{
						try
						{
							(*stock).at(item.getID()).setColor(input);
							cout << "Successfully Changed Item Color" << endl;
							selected = true;
						}
						catch (domain_error e) { cout << "Invalid Length of String" << endl; }
					}
				}
				selected = false;
			}
			else if (regex_search(input, matches, SizeReg) || input == "3")
			{
				while (!selected)
				{
					cout << endl;
					cout << "Please Select new Size" << endl;
					input = "";
					cout << "1: XS" << endl;
					cout << "2: S" << endl;
					cout << "3: M" << endl;
					cout << "4: L" << endl;
					cout << "5: XL" << endl;
					getline(cin, input);

					if (input != "")
					{
						if (input == "1" || input == "XS" || input == "xs")
						{
							string size = "XS";
							(*stock).at(item.getID()).setSize(size);
							cout << "Successfully Changed Item Size" << endl;
							selected = true;
						}
						else if (input == "2" || input == "S" || input == "s")
						{
							string size = "S";
							(*stock).at(item.getID()).setSize(size);
							cout << "Successfully Changed Item Size" << endl;
							selected = true;
						}
						else if (input == "3" || input == "M" || input == "m")
						{
							string size = "M";
							(*stock).at(item.getID()).setSize(size);
							cout << "Successfully Changed Item Size" << endl;
							selected = true;
						}
						else if (input == "4" || input == "L" || input == "l")
						{
							string size = "L";
							(*stock).at(item.getID()).setSize(size);
							cout << "Successfully Changed Item Size" << endl;
							selected = true;
						}
						else if (input == "5" || input == "XL" || input == "xl")
						{
							string size = "XL";
							(*stock).at(item.getID()).setSize(size);
							cout << "Successfully Changed Item Size" << endl;
							selected = true;
						}
						else
						{
							cout << "Invalid Input" << endl;
						}
					}
				}
				selected = false;
			}
			else if (regex_search(input, matches, QuanityReg) || input == "4")
			{
				while (!selected)
				{
					cout << "Enter  new Quantity" << endl;
					newValue = intValidator();
					(*stock).at(item.getID()).setQuantity(newValue);
					selected = true;
				}
				selected = false;
			}
			else if (regex_search(input, matches, PriceReg) || input == "5")
			{
				while (!selected)
				{
					cout << "Enter  new Price" << endl;
					newPrice = floatValidator();
					(*stock).at(item.getID()).setCost(newPrice);
					selected = true;
				}
				selected = false;
			}

			else if (regex_search(input, matches, BackReg) || input == "6")
			{
				selected = true;
				mainMenu();
			}
			else
			{
				cout << "Invalid Input" << endl;
			}
		}


	}
#pragma endregion

#pragma region searchStock

	void searchStockMenu()
	{
		bool selected = false;
		smatch matches;
		string input;
		regex AllReg("[Aa][Ll][Ll]$");
		regex TitleReg("[Tt][Ii][Tt][Ll][Ee]$");
		regex ColorReg("[Cc][Oo][Ll][Oo][Rr]$");
		regex SizeReg("[Ss][Ii][Zz][Ee]$");
		regex BackReg("[Bb][Aa][Cc][Kk]$");




		vector<StockItem> results;
		while (!selected)
		{
			cout << "---Search---" << endl << endl;

			cout << "1: Search All" << endl;
			cout << "2: Search Title" << endl;
			cout << "3: Search Color" << endl;
			cout << "4: Search Size" << endl;
			cout << "5: back" << endl;


			getline(cin, input);


			if (input == "1" || regex_search(input, matches, AllReg))
			{
				function <bool(StockItem)> pFunc = [](StockItem item)
				{
					return item.getID() > 100 ? true : false;
				};

				results = searchStockBy(pFunc, (*stock));
				printStockVector(results);
			}

			else if (input == "2" || regex_search(input, matches, TitleReg))
			{
				while (!selected)
				{
					cout << "Enter Title" << endl;
					getline(cin, input);
					transform(input.begin(), input.end(), input.begin(), ::toupper);

					function <bool(StockItem)> pFunc = [input](StockItem item)
					{
						return item.getTitle() == input ? true : false;
					};

					results = searchStockBy(pFunc, (*stock));
					printStockVector(results);
					selected = true;
				}
				selected = false;

			}
			else if (input == "3" || regex_search(input, matches, ColorReg))
			{
				while (!selected)
				{
					cout << "Enter Color" << endl;
					getline(cin, input);
					transform(input.begin(), input.end(), input.begin(), ::toupper);

					function <bool(StockItem)> pFunc = [input](StockItem item)
					{
						return item.getColor() == input ? true : false;
					};

					results = searchStockBy(pFunc, (*stock));
					printStockVector(results);
					selected = true;
				}
				selected = false;
			}
			else if (input == "4" || regex_search(input, matches, SizeReg))
			{
				while (!selected)
				{
					cout << "Please Select Search Size" << endl;
					input = "";
					cout << "1: XS" << endl;
					cout << "2: S" << endl;
					cout << "3: M" << endl;
					cout << "4: L" << endl;
					cout << "5: XL" << endl;
					getline(cin, input);

					if (input != "")
					{
						if (input == "1" || input == "XS" || input == "xs")
						{
							input = "XS";
							selected = true;
						}
						else if (input == "2" || input == "S" || input == "s")
						{
							input = "S";
							selected = true;
						}
						else if (input == "3" || input == "M" || input == "m")
						{
							input = "M";
							selected = true;
						}
						else if (input == "4" || input == "L" || input == "l")
						{
							input = "L";
							selected = true;
						}
						else if (input == "5" || input == "XL" || input == "xl")
						{
							input = "XL";
							selected = true;
						}
						else
						{
							cout << "Invalid Input" << endl;
						}
					}
				}
				selected = false;

				function <bool(StockItem)> pFunc = [input](StockItem item)
				{
					return item.getSize() == input ? true : false;
				};

				results = searchStockBy(pFunc, (*stock));
				printStockVector(results);
	
			}
			else if (input == "5" || regex_search(input, matches, BackReg)) { selected = true;  mainMenu(); }
			else { cout << "Invalid Input" << endl; }
		
		}
	}
			

#pragma endregion


#pragma endregion

#pragma region addSaleMenu

	void addSaleMenu()
	{
		bool selected = false;
		int option = -1;
		string input;

		while (!selected)
		{
			cout << endl;
			cout << "---Sale Menu---" << endl << endl;
			cout << "1: New Sale" << endl;
			cout << "2: Back" << endl;
			getline(cin, input);
			option = addStockMenuCast(input);

			switch (option)
			{
			case newSale: {selected = true; addNewSale(); }
			case Salesback: {selected = true; mainMenu(); }
			case error: {cout << "Error Returning to main menu" << endl; mainMenu(); }
			}

		}
	}


	void addNewSale()
	{
		createSale();
	}

#pragma endregion

#pragma region analyseSalesMenu
	void analyseSalesMenu() 
	{
		createAnalysis();
		mainMenu();
	}
#pragma endregion

#pragma region removeItemMenu
	void removeItemMenu() 
	{
		bool selected = false;
		smatch matches;
		string IDinput;
		regex IDReg("^[0-9]+$");
		while (!selected)
		{
			cout << "Enter ID of Item you wish to remove from the store" << endl ;
			getline(cin, IDinput);

			if (regex_search(IDinput, matches, IDReg))
			{
				try
				{
					int ID = stoi(IDinput);
					store.removeStockItem(ID);
					cout << "Successfully removed Item from Stock" << endl;
					selected = true;
				}
				catch (out_of_range & e)
				{

				}
			}
		}
		mainMenu();
	}
#pragma endregion

#pragma region quit
	void quitApplocation()
	{
		exit(1);
	}
#pragma endregion
