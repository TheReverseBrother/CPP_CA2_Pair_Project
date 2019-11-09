#pragma once

int mainMenuOptionCast(string input);


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
#pragma endregion



void mainMenu()
{
	int option;
	string input;
	bool selected = fasle;

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
		case addStock: {}
		case addSale: {}
		case analyseSales: {}
		case searchStock: {}
		case removeItem: {}
		case quit: {}
		case error: {}
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
			else if(regex_search(input, matches, addSaleReg)){ return addSale; }
			else if (regex_search(input, matches, analyseSalesReg)) { return analyseSales; }
			else if (regex_search(input, matches, searchStockReg)) { return searchStock; }
			else if (regex_search(input, matches, removeItemReg)) { return removeItem; }
			else if (regex_search(input, matches, quitReg)) { return quit; }
		}
		else {return -1;}
	}
	return option;
}