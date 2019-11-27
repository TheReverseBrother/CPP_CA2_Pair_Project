#pragma once

#pragma region method definitions
void addStockMenu();
void modifyStockMenu();
StockItem searchStockByID(int id);
void addSaleMenu();
void analyseSalesMenu();
void searchStockMenu();
void removeItemMenu();
void addNewStockItem();
void addNewSale();
void refundSaleMenu();
int mainMenuOptionCast(string input);
int addStockMenuCast(string input);



void quitApplocation();
#pragma endregion

#pragma region Definitions

multiset<StockItem> stock;

#pragma endregion



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
		stock.insert(item);

	}

	addStockMenu();
}


void modifyStockMenu()
{
	bool selected = false;
	smatch matches;
	string IDinput;
	regex IDReg("^[0-9]+$");

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
				
				item = searchStockByID(ID);
				if (item.getID() == -1) 
				{
					cout << "No item has this id " << endl;
				}
				else 
				{
					selected = true;

					



			

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
		case newSale: {selected = true; /*addNewSale();*/ }
		case refundSale: {selected = true; /*refundSaleMenu();*/ }
		case back: {selected = true; mainMenu(); }
		case error: {cout << "Error Returning to main menu" << endl; mainMenu(); }
		}

	}
}

#pragma endregion

#pragma region analyseSalesMenu
void analyseSalesMenu() {}
#pragma endregion

#pragma region searchStockMenu
void searchStockMenu() {}


#pragma region  Searches


StockItem searchStockByID(int id)
{
	StockItem item;

	for (auto it = stock.begin(); it != stock.end(); it++)
	{
		item = *it;
		if (item.getID() == id)
		{
			return item;
		}
		else 
		{
			return item = StockItem(-1, "null", "null", "null", 0, 0);
		}
		

	}



}


#pragma endregion



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

