#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
using namespace std;


class clsDepositScreen : protected clsScreen
{

	static void _PrintClient(clsBankClient client)
	{
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

	static string _ReadAccountNumber() {

		string AccountNumber = "";
		cout << "\nEnter The Account Number : ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public : 

	static void ShowDepositScreen() {

		clsScreen::_DrawScreenHeader("Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!(clsBankClient::IsClientExist(AccountNumber))) {

			cout << "\n\nClient With [" << AccountNumber << "] does not exist.";

			AccountNumber = _ReadAccountNumber();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		double Amount = 0;

		char Answare = 'y';

		cout << "\nPlease enter deposit Amount? ";
		cin >> Amount;

		cout << "\n\nAre you sure you want to perform this transaction? ";
		cin >> Answare;

		if (Answare == 'y' || Answare == 'Y') {

			Client1.Deposit(Amount);

			cout << "\nAmount Deposited Successfully.";
			cout << "\n\nNew Balance Is : " << Client1.AccountBalance;
		}
		else {
			cout << "\nThe Operation was Cancelled.";

		}


	}

};
