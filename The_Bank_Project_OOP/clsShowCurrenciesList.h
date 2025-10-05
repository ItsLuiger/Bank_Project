#pragma once

#include <iostream>
#include "clsScreen.h";
#include "clsCurrency.h";
#include "iomanip";
using namespace std;

class clsShowCurrenciesList : protected clsScreen
{

	static void _PrintCurrenciesList(clsCurrency current) {

		cout << setw(8) << left << "" << "| " << left << setw(30) << current.Country();
		cout << "| " << left << setw(12) << current.CurrencyCode();
		cout << "| " << left << setw(30) << current.CurrencyName();
		cout << "| " << left << setw(20) << current.Rate();
	}

public : 

	static void ShowCurrenciesList() {

		vector <clsCurrency> Currencies = clsCurrency::GetCurrenciesList();

		string Title = "Currencies List Screen";
		string Substitle = "\t(" + to_string(Currencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, Substitle);

		cout << "\n\t-----------------------------------------------------------------------------------------\n";

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(12) << "Code";
		cout << "| " << left << setw(30) << "Name";
		cout << "| " << left << setw(20) << "Rate/(1$)";

		cout << "\n\t-----------------------------------------------------------------------------------------\n";

		for (clsCurrency C : Currencies) {

			_PrintCurrenciesList(C);
			cout << endl;
		}

		cout << "\n\t-----------------------------------------------------------------------------------------\n";

	}

};

