#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

	static void _ReadClientInfo(clsBankClient& client) {

		cout << "\nEnter FirstName: ";
		client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

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
	
	static void ShowUpdateClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::eUpd)) {

			return;
		}

		clsScreen::_DrawScreenHeader("Update Client Screen");

		string AccountNumber;

		cout << "Please Enter client Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber))) {

			cout << "\nAccount number is not found, choose another one: ";

			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n\nUpdate Client Info:";
		cout << "\n______________________";

		_ReadClientInfo(Client1);
	
		cout << "\n";

		_PrintClient(Client1);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client1.Save();

		switch (SaveResult) {

		case clsBankClient::enSaveResults::svSucceeded:

			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client1);
			break;

		case clsBankClient::enSaveResults::svFaildEmptyObject:

			cout << "\nError Account was not saved because it's Empty";
			break;
		}

	}

};

