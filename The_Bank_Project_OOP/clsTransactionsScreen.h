#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsMainScreen.h";
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

	enum enTransactionsOption {
		eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eTransfer = 4, eTransferLog = 5 , eMainMenu = 6
	};

	static void _ShowDepositScreen() {

		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {

		clsWithdrawScreen::ShowWithdrawScreen();

	}

	static void _ShowTotalBalancesScreen() {

		clsTotalBalancesScreen::ShowTotalBalancesScreen();

	}

	static void _ShowTransferScreen() {

		clsTransferScreen::ShowTransferScreen();
	
	}

	static void _ShowTransferLogScreen() {

		clsTransferLogScreen::ShowTransferLogScreen();

	}

	static void _GoBackToTransactionsMenue() {

		cout << "\n\n\tPress Any Key to go back to Main Menue...";
		system("pause>0");
		showTransactionsMenue();

	}

	static short _ReadShowTransactionsMenuOption() {

		cout << "Choose What do you want to do? [1 to 6] ? ";
		short Choose = clsInputValidate::ReadIntNumberBetween(1, 6, "Choose What do you want to do? [1 to 6] ? ");

		return Choose;
	}

	static void _PerfromShowTransactionsMenuOption(enTransactionsOption ShowTransactionsMenuOption) {

		switch (ShowTransactionsMenuOption) {

		case enTransactionsOption::eDeposit:

			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsOption::eWithdraw:

			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsOption::eTotalBalance:

			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsOption::eTransfer:

			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsOption::eTransferLog:

			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsOption::eMainMenu:
			
			break;
		}

	}

public : 

	static void showTransactionsMenue() {

		if (!CheckAccessRights(clsUser::enPermissions::eTransactions)) {

			return;
		}

		system("cls");

		clsScreen::_DrawScreenHeader("Transactions Screen");

		cout << "===============================================\n";
		cout << "                Transactions Screen\n";
		cout << "===============================================\n";
		cout << "        [1] Deposit.\n";
		cout << "        [2] Withdraw.\n";
		cout << "        [3] Total Balances.\n";
		cout << "        [4] Transfer.\n";
		cout << "        [5] Transfer Log.\n";
		cout << "        [5] Main Menue.\n";
		cout << "===============================================\n";

		_PerfromShowTransactionsMenuOption((enTransactionsOption)_ReadShowTransactionsMenuOption());


	}

};

