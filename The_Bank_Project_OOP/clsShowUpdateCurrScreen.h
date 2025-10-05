#pragma once

#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsCurrency.h";

using namespace std;

class clsShowUpdateCurrScreen : protected clsScreen
{

	static float _ReadRate() {

		cout << "\nEnter New Rate : ";
		float NewRate;

		NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;

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


public : 

	static void ShowUpdateCurrScreen() {

		_DrawScreenHeader("Update Currency Screen");

		cout << "\nPlease Enter Currency Code: ";
		string Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code)) {

			cout << "\nThe Current Not Found , choose another code : ";
			Code = clsInputValidate::ReadString();
		}

		clsCurrency  Currency = clsCurrency::FindByCode(Code);
		_PrintCurrencyCard(Currency);

		cout << "\nAre you sure you want to update the rate of this currency y/n? ";

		char Answare = clsInputValidate::CheckAnsware();

		if (Answare == 'y' || Answare == 'Y') {

				cout << "\n\nUpdate Currency Rate:";
				cout << "\n___________________________\n";
				Currency.UpdateRate(_ReadRate());

				cout << "\nCurrency Rate Updated Successfully :-)\n";
				_PrintCurrencyCard(Currency);

		}

	}

};

