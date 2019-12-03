#pragma once
#include <functional>


#pragma region Definitions

map<int, StockItem> stock;

#pragma endregion


#pragma region method definitions
void addStockMenu();
void modifyStockMenu();
Sale createSale();
void addSaleMenu();
void analyseSalesMenu();
void searchStockMenu();
void removeItemMenu();
void addNewStockItem();
void addNewSale();
void ModifyStock(StockItem item);
void refundSaleMenu();
int mainMenuOptionCast(string input);
int addStockMenuCast(string input);


auto Pfunc = [](string input){};


		
void quitApplocation();
#pragma endregion


vector<StockItem> searchStockBy(function<bool(StockItem)> Pfunc, map<int, StockItem> stock)
{
	vector<StockItem> results;

	for (StockItem n : results) 
	{
		if (Pfunc(n)) 
		{
			results.push_back(n);
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
	refundSale = 2,

};
#pragma endregion

#pragma region mainMenu



void mainMenu()
{
	int option;
	string input;
	bool selected = false;

	while (!selected)
	{

		cout << "Main Menu" << endl << endl;
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
		case error: {selected = true;  cout << "Error Returning to main menu" << endl; mainMenu(); }
		}
	}
}


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
			cout << "invaild Menu Selection in Main Menu" << endl;
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
		cout << "Stock Menu" << endl << endl;
		cout << "1: New Item" << endl;
		cout << "2: Modify Stock" << endl;
		cout << "3: Back" << endl;
		getline(cin, input);
		option = addStockMenuCast(input);

		switch (option)
		{
		case newItem: {selected = true; addNewStockItem(); }
		case modifyStock: {selected = true; modifyStockMenu(); }
		case back: {selected = true; mainMenu(); }
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
			selected = true;
		}

		selected = false;

		while (!selected)
		{
			cout << "please enter stock Item Color" << endl;
			getline(cin, color);
			selected = true;
		}
		selected = false;

		while (!selected)
		{
			cout << "please enter stock Item Size 'XS, S, M, L, XL'" << endl;
			getline(cin, size);
			selected = true;
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

		StockItem item (title, color, size, quantity, cost);
		stock.insert(make_pair(item.getID(),item));

	}

	addStockMenu();
}
#pragma endregion

#pragma region modifyStockMenu
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
		cout << "Modify Stock" << endl << endl;
		cout << "enter any letter to return to Stock menu" << endl << endl;
		cout << "Enter Stock ID" << endl;
		getline(cin, IDinput);

		if (regex_search(IDinput, matches, IDReg))
		{
			try
			{
				int ID = stoi(IDinput);
				
				function <bool(StockItem)> pFunc = [ID](StockItem item)
				{
					
					return item.getID() == ID ? true : false;
				};

				results = searchStockBy(pFunc,stock);

				if (results.size() == 1) 
				{
					selected = true;
					ModifyStock(results.front());
				}
				else
				{
					cout << "No Item With Matching ID" << endl;
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
void ModifyStock (StockItem item) 
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


	while (!selected)
	{
		cout << "Modify Stock" << endl << endl;
		cout << "1: Title" << endl;
		cout << "2: Color" << endl;
		cout << "3: Size" << endl;
		cout << "4: Quanity" << endl;
		cout << "5: Price" << endl ;
		cout << "6: Back" << endl ;
		getline(cin,input);

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
						item.setTitle(input);
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
						item.setColor(input);
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
						item.setSize(size);
						cout << "Successfully Changed Item Size" << endl;
					selected = true;
					}
					if (input == "2" || input == "S" || input == "s") 
					{ 
						string size = "S";
						item.setSize(size);
						cout << "Successfully Changed Item Size" << endl;
						selected = true;
					}
					if (input == "3" || input == "M" || input == "m") 
					{ 
						string size = "M";
						item.setSize(size);
						cout << "Successfully Changed Item Size" << endl;
						selected = true;
					}
					if (input == "4" || input == "L" || input == "l") 
					{ 
						string size = "L";
						item.setSize(size);
						cout << "Successfully Changed Item Size" << endl;
						selected = true;
					}
					if (input == "5" || input == "XL" || input == "xl") 
					{ 
						string size = "XL"; 
						item.setSize(size);
						cout << "Successfully Changed Item Size" << endl;
						selected = true;
					}
				}
			}
			selected = false;
		}
		else if (regex_search(input, matches, QuanityReg) || input == "4")
		{

		}
		else if (regex_search(input, matches, PriceReg) || input == "5")
		{

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


#pragma endregion

#pragma region addSaleMenu

void addSaleMenu()
{
	bool selected = false;
	int option = -1;
	string input;

	while (!selected)
	{
		cout << "Sale Menu" << endl << endl;
		cout << "1: New Sale" << endl;
		cout << "2: Refund Sale" << endl;
		cout << "3: Back" << endl;
		getline(cin, input);
		option = addStockMenuCast(input);

		switch (option)
		{
		case newSale: {selected = true; addNewSale(); }
		case refundSale: {selected = true; /*refundSaleMenu();*/ }
		case back: {selected = true; mainMenu(); }
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
void analyseSalesMenu() {}
#pragma endregion

#pragma region removeItemMenu
void removeItemMenu() {}
#pragma endregion

#pragma region quit
void quitApplocation()
{

	
	StockItem::saveStock(stock);
	//Sale::saveSales(Sales);
	//SalesAnalysis::saveAnalysises(AnalysisList);

	exit(1);
}
#pragma endregion

