#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";

using namespace std;


class clsDeleteUserScreen : protected clsScreen
{

	static void _PrintUser(clsUser& User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}


public :

	static void ShowDeleteUserScreen() {

		clsScreen::_DrawScreenHeader("Delete User Screen");

		cout << "\nPlease Enter UserName: ";
		string UserName = clsInputValidate::ReadString();

		while (!(clsUser::IsUserExist(UserName))) {

			cout << "\nUser is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();


		}

		clsUser User1 = clsUser::Find(UserName);

		_PrintUser(User1);

		char Answare = 'n';
		cout << "\n\nAre you sure you want to delete this user y/n? ";
		cin >> Answare;

		if (Answare == 'y' || Answare == 'Y') {


			if (User1.Delete()) {

				cout << "\n\nUser Deleted Succesfully :-)";

				_PrintUser(User1);
			}
			else {

				cout << "\nError User was not Deleted :( .";

			}

		}
		


	}


};

