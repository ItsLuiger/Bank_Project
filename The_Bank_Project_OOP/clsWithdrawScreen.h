#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
using namespace std;


class clsWithdrawScreen : protected clsScreen
{

	static void _PrintClient(clsBankClient client) {

		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << client.FirstName;
		cout << "\nLastName    : " << client.LastName;
		cout << "\nFull Name   : " << client.FullName();
		cout << "\nEmail       : " << client.Email;
		cout << "\nPhone       : " << client.Phone;
		cout << "\nAcc. Number : " << client.AccountNumber();
		cout << "\nPassword    : " << client.PinCode;
		cout << "\nBalance     : " << client.AccountBalance;
		cout << "\n___________________\n";


	}


public :

	static void ShowWithdrawScreen() {

		clsScreen::_DrawScreenHeader("Withdraw Screen");

		cout << "\nPlease Enter AccountNumber? ";

		string AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber))) {

			cout << "\n\nClient With [" << AccountNumber << "] does not exist. Enter a Aalid Account Number : ";

			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(client1);

		double Amount = 0;

		char Answare = 'y';

		cout << "\nPlease enter Withdraw Amount? ";
		cin >> Amount;

		cout << "\n\nAre you sure you want to perform this transaction? ";
		cin >> Answare;

		if ((Answare == 'y' || Answare == 'Y')) {

			if (client1.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << client1.AccountBalance;

			}
		}
		else {

			cout << "\nOperation was cancelled.\n";

		}

	}


};