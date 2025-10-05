#pragma once
#include <iostream>
#include "clsScreen.h";
#include <iomanip>
#include "clsMainScreen.h"
#include "clsGlobal.h"

class clsLoginScreen : protected clsScreen
{

	static bool _Login() {

		bool LoginFail = false;
		short FaildLoginCount = 0;

		string UserName, Password;


		do {

			if (LoginFail) {

				cout << "\n\nInvalid UserName/Password!";
				FaildLoginCount += 1;
				cout << "\nYou Have [" << 3 - FaildLoginCount << "] Trials to login.";

			}

			if (FaildLoginCount == 3) {

				cout << "\n\nYour are Locked after 3 faild trails \n\n";
				return false;

			}

			cout << "\n\nEnter UserName? ";
			cin >> UserName;

			cout << "\nEnter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFail = CurrentUser.IsEmpty();

		} while (LoginFail);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
		return true;
	}


public : 

	static bool ShowLoginScreen() {

		system("cls");
		clsScreen::_DrawScreenHeader("Login Screen");
		return _Login();
	}

};

