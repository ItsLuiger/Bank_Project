#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";

using namespace std;



class clsAddNewClientScreen : protected clsScreen
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

	static void ShowAddNewClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::eAdd)) {

			return;
		}

		clsScreen::_DrawScreenHeader("Add New Client Screen");

		string AccountNumber = "";

		cout << "Enter The New Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nThe Account Number is Reserved Please Enter another Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}
	}

};

