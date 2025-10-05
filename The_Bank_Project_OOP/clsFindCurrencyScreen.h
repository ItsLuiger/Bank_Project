#pragma once

#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsCurrency.h";

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{

	static short _ReadChoice() {

		cout << "\nFind By: [1] Code or [2] Country ? ";

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 2, "\nFind By: [1] Code or [2] Country ? ");

		return Choice;
	}

	static void _PrintCurrencyCard(clsCurrency Current) {

		cout << "\n\nCurrency Card: ";
		cout << "\n\n----------------------------------------\n\n";
		cout << "  - Country     : " << Current.Country() << endl;
		cout << "  - Code        : " << Current.CurrencyCode() << endl;
		cout << "  - Name        : " << Current.CurrencyName() << endl;
		cout << "  - Rate(1$) =  : " << Current.Rate();
		cout << "\n\n----------------------------------------\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public : 

	static void ShowFindCurrencyScreen() {

		_DrawScreenHeader("Find Currency Screen");

		short Choice = _ReadChoice();

		switch (Choice) {

		case 1: {


			cout << "\nPlease Enter CurrencyCode: ";
			string CurrencyCode = clsInputValidate::ReadString();

			clsCurrency Current = clsCurrency::FindByCode(CurrencyCode);

			_ShowResults(Current);

			break;
		}
		
		case 2: 

			cout << "\nPlease Enter Country: ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Current = clsCurrency::FindByCountry(Country);
			_ShowResults(Current);
			break;
		

		}


	}

};

