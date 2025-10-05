#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
using namespace std;

class clsTransferScreen : protected clsScreen
{

	static void _PrintClientCard(clsBankClient& client) {

		cout << "\n\nClient Card: ";
		cout << "\n__________________________________________";

		cout << "\n\nFull Name	:" << client.FullName();
		cout << "\nAcc. Number	:" << client.AccountNumber();
		cout << "\nBalance		:" << client.AccountBalance;

		cout << "\n__________________________________________";

	}

	static string _ReadAccountNumber(string AccDes) {

		cout << "\n\nPlease Enter Account Number to Transfer " << AccDes << " : ";

		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number not found , choose another Acc. Number :  ";

			AccountNumber = clsInputValidate::ReadString();

		}

		return AccountNumber;

	}

	static float _ReadAmount(clsBankClient& client) {

		cout << "\n\nEnter Transfer Amount? ";
		float Amount = clsInputValidate::ReadDblNumber();

		while (Amount > client.AccountBalance) {

			cout << "\nAmount Exceeds the available Balance, Enter another Amount? ";
			Amount = clsInputValidate::ReadDblNumber();

		}
		return Amount;
	}

public :

	static void ShowTransferScreen() {

		clsScreen::_DrawScreenHeader("Transfer Screen");

		string AccountNumber = _ReadAccountNumber("From");

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client);

		string AccountNumberDest = _ReadAccountNumber("To");

		while (AccountNumber == AccountNumberDest) {

			cout << "\nyou can't Send Money to Your Self HaHa .";

			AccountNumberDest = _ReadAccountNumber("To");

		}

		clsBankClient ClientDest = clsBankClient::Find(AccountNumberDest);

		_PrintClientCard(ClientDest);

		float Amount = _ReadAmount(Client);

		cout << "\nAre you sure you want to perform this operatin? y/n? ";

		char Answare = clsInputValidate::CheckAnsware();

		if (Answare == 'Y' || Answare == 'y') {

			if (Client.Transfer(Amount, ClientDest , CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}

		}
		else {

			cout << "\n\t\tThe Opeation was Failed :(.";
		}

		_PrintClientCard(Client);
		_PrintClientCard(ClientDest);

	}

};

