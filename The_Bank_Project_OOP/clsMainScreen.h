#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsClientListScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsManageUsers.h";
#include "clsUser.h";
#include "clsShowLoginRegister.h";
#include "clsCurrencyMainScreen.h";
#include "clsGlobal.h";
using namespace std;

class clsMainScreen: protected clsScreen
{


	enum enMenuOption { Show = 1, Add = 2, Del = 3, Upd = 4, Find = 5, Transactions = 6,
		ManageUsers = 7, eLoginRegister = 8 , eCurrencyExchange = 9 , eLogout = 10 };

	static void _GoBackToMainMenue() {

		cout << "\n\n\tPress Any Key to go back to Main Menue...";
		system("pause>0");
		ShowMainMenu();
	}
	
	static void _ShowClient() {

		clsClientListScreen::ShowClientList();

	}

	static void _ShowAddClient() {

		clsAddNewClientScreen::ShowAddNewClientScreen();

	}

	static void _ShowDeleteClient() {

		clsDeleteClientScreen::ShowDeleteClientScreen();

	}

	static void _ShowUpdateClient() {

		clsUpdateClientScreen::ShowUpdateClientScreen();

	}

	static void _ShowFindClient() {

		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransactions() {

		clsTransactionsScreen::showTransactionsMenue();

	}

	static void _ShowManageUsers() {

		clsManageUsers::ShowManageUsersScreen();

	}

	static void _ShowLoginRegister() {

		clsShowLoginRegister::ShowLoginRegister();

	}

	static void _ShowCurrencyExchange() {

		clsCurrencyMainScreen::ShowCurrencyExchangeScreen();


	}

	static short _ReadShowMainMenuOption() {

		cout << "Choose What do you want to do? [1 to 10] ? ";
		short Choose = clsInputValidate::ReadIntNumberBetween(1, 10, "Choose What do you want to do? [1 to 10] ? ");

		return Choose;
	}

	static void _Logout() {
		
		CurrentUser = clsUser::Find("", "");

	}

	static void _PerfromShowMainMenueOption(enMenuOption ShowMainMenuOption) {

		switch (ShowMainMenuOption) {

		case enMenuOption::Show:

			system("cls");
			_ShowClient();
			_GoBackToMainMenue();
			break;

		case enMenuOption::Add:

			system("cls");
			_ShowAddClient();
			_GoBackToMainMenue();
			break;

		case enMenuOption::Del:

			system("cls");
			_ShowDeleteClient();
			_GoBackToMainMenue();
			break;

		case enMenuOption::Upd:

			system("cls");
			_ShowUpdateClient();
			_GoBackToMainMenue();
			break;

		case enMenuOption::Find:

			system("cls");
			_ShowFindClient();
			_GoBackToMainMenue();
			break;

		case enMenuOption::Transactions:

			system("cls");
			_ShowTransactions();
			_GoBackToMainMenue();
			break;

		case enMenuOption::ManageUsers:

			system("cls");
			_ShowManageUsers();
			_GoBackToMainMenue();
			break;

		case enMenuOption::eLoginRegister:

			system("cls");
			_ShowLoginRegister();
			_GoBackToMainMenue();
			break;

		case enMenuOption::eCurrencyExchange:

			system("cls");
			_ShowCurrencyExchange();
			_GoBackToMainMenue();
			break;

		case enMenuOption::eLogout:

			system("cls");
			_Logout();
			break;

		}



	}

public : 

	static void ShowMainMenu() {

		system("cls");
		
		clsScreen::_DrawScreenHeader("Menu Screen");

		cout << "===============================================\n";
		cout << "                Main Menue Screen\n";
		cout << "===============================================\n";
		cout << "        [1] Show Client List.\n";
		cout << "        [2] Add New Client.\n";
		cout << "        [3] Delete Client.\n";
		cout << "        [4] Update Client Info.\n";
		cout << "        [5] Find Client.\n";
		cout << "        [6] Transactions.\n";
		cout << "        [7] Manage Users.\n";
		cout << "        [8] Login Register.\n";
		cout << "        [9] Currency Exchange.\n";
		cout << "        [10] eLogout.\n";
		cout << "===============================================\n";

		_PerfromShowMainMenueOption((enMenuOption)_ReadShowMainMenuOption());

	}

};

