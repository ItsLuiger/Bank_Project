#pragma once

#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsMainScreen.h";
#include "clsShowCurrenciesList.h";
#include "clsFindCurrencyScreen.h";
#include "clsShowUpdateCurrScreen.h";
#include "clsUpdateCurrencyScreen.h";

class clsCurrencyMainScreen :protected clsScreen
{

	enum enCurrencyExchange { eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5 };

	static short _ReadShowCurrencyMainOption() {

		cout << "\n\tChoose What do you want to do? [1 to 5]? ";

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "\n\tChoose What do you want to do? [1 to 5]?");

		return Choice;

	}

	static void _GoBackToCurrencyExchangeScreen() {

		cout << "\n\n\tPress Any Key to go back to Main Menue...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
		
	}

	static void _ShowListCurrencyExchange() {

		clsShowCurrenciesList::ShowCurrenciesList();

	}

	static void _ShowFindCurrencyExchange() {

		clsFindCurrencyScreen::ShowFindCurrencyScreen();

	}

	static void _ShowUpdateRate() {

		clsShowUpdateCurrScreen::ShowUpdateCurrScreen();

	}

	static void _ShowCurrencyCalculator() {

		clsUpdateCurrencyScreen::ShowCurrencyCalculatorScreen();

	}

	static void _PerfromShowMainCurrencyExchangeOption(enCurrencyExchange ShowMainCurrencyExchange) {

		switch (ShowMainCurrencyExchange) {

		case enCurrencyExchange::eListCurrency:

			system("cls");
			_ShowListCurrencyExchange();
			_GoBackToCurrencyExchangeScreen();
			break;

		case enCurrencyExchange::eFindCurrency:

			system("cls");
			_ShowFindCurrencyExchange();
			_GoBackToCurrencyExchangeScreen();
			break;

		case enCurrencyExchange::eUpdateRate:

			system("cls");
			_ShowUpdateRate();
			_GoBackToCurrencyExchangeScreen();
			break;

		case enCurrencyExchange::eCurrencyCalculator:

			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToCurrencyExchangeScreen();
			break;

		case enCurrencyExchange::eMainMenue:
			
			break;

		}

	}
	
public : 

	static void ShowCurrencyExchangeScreen() {

		system("cls");

		_DrawScreenHeader("Currency Exchange Main Screen");

		cout << "\n\t====================================================\n";
		cout << "\t\t\tCurrency Exchange Menue";
		cout << "\n\t====================================================\n";
		cout << "\n\t\t[1] List Currencies.";
		cout << "\n\t\t[2] Find Currencies.";
		cout << "\n\t\t[3] Update Rate.";
		cout << "\n\t\t[4] Currency Calculator.";
		cout << "\n\t\t[5] Main Menue.";
		cout << "\n\t====================================================";
		
		_PerfromShowMainCurrencyExchangeOption(enCurrencyExchange(_ReadShowCurrencyMainOption()));
	}

};

