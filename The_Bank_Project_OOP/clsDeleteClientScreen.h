#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";

using namespace std;


class clsDeleteClientScreen : protected clsScreen
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

public : 
	
	static void ShowDeleteClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::eDel)) {

			return;
		}

		clsScreen::_DrawScreenHeader("Delete Client Screen");

		string AccountNumber = "";
		cout << "Enter The Account Number you want delete : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!(clsBankClient::IsClientExist(AccountNumber))) {

			cout << "\nThe Account Number Not found Please enter A valid Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		cout << "\nAre you sure you want delete this client? : ";

		char Answare = 'n';
		cin >> Answare;

		if (Answare == 'y' || Answare == 'Y') {

			if (Client1.Delete()) {

				cout << "\nThe Client is Deleted Successfully :) .";

			_PrintClient(Client1);

			}
			else {

				cout << "\nError Client was not Deleted :( .";

			}

		}

	}


};

