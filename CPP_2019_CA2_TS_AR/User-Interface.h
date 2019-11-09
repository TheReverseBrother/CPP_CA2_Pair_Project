#pragma once

int mainMenuOptionCast(string input);

void mainMenu()
{
	int option;
	string input;

	cout << "Main Menu" << endl << endl ;
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
	case 1: cout << '1'; // prints "1",
	case 2: cout << '2'; // then prints "2"
	}
}


int mainMenuOptionCast(string input) 
{
	int option;

	string temp = input.substr(0, input.find(" "));

	if (temp.length() == 1) 
	{
		cout << "success" << endl;
		option = 1;
	}
	else
	{
		cout << "fail" << endl;
		option = -1;
	}



	return option;
}