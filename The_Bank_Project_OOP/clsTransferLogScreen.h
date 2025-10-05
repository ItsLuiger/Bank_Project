#pragma once
#include <iostream>
#include "clsScreen.h";
#include <iomanip>
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
    static void _PrintLoginTransferRegisterRecordLine(clsBankClient::stLogTransferRegister Record) {


        cout << setw(8) << left << "" << "| " << left << setw(35) << Record.DateTime;
        cout << "| " << left << setw(20) << Record.SAccountNumber;
        cout << "| " << left << setw(20) << Record.DesAccountNumber;
        cout << "| " << left << setw(20) << Record.Amount;
        cout << "| " << left << setw(20) << Record.SBalance;
        cout << "| " << left << setw(10) << Record.DesBalance;
        cout << "| " << left << setw(10) << Record.UserName << left << setw(8) << "|";
        

    }


public  :

	static void ShowTransferLogScreen() {

		vector <clsBankClient::stLogTransferRegister> vLogTransfer = clsBankClient::GetLoginTransferRegisterList();

		string Title = "Transfer Log List Screen";
		string Subtitle = "\t(" + to_string(vLogTransfer.size()) + ") Record(s).";

		_DrawScreenHeader(Title , Subtitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "s.Acc";
        cout << "| " << left << setw(20) << "d.Acc";
        cout << "| " << left << setw(20) << "Amount";
        cout << "| " << left << setw(20) << "s.Blance";
        cout << "| " << left << setw(10) << "d.Blance";
        cout << "| " << left << setw(10) << "User" << left << setw(8) << "|";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________________________________________________\n" << endl;

        if (vLogTransfer.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stLogTransferRegister Record : vLogTransfer)
            {

                _PrintLoginTransferRegisterRecordLine(Record);
                cout << endl;
            }
            cout << endl << setw(8) << left << "" << "______________________________________________________________________________________________________________________________________________________\n" << endl;


	}


};

