#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUser.h";
using namespace std;

class clsFindUserScreen : protected clsScreen
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

	static void ShowFindUserSccreen() {

		clsScreen::_DrawScreenHeader("Find User Screen");

		cout << "\n\nPlease Enter UserName : ";
		string UserName = clsInputValidate::ReadString();

		while (!(clsUser::IsUserExist(UserName))) {

			cout << "\n\nUser Is Not found , choose another one: ";

			UserName = clsInputValidate::ReadString();
		}

		cout << "\n\nUser Found :-)\n";

		clsUser user = clsUser::Find(UserName);

		_PrintUser(user);

	}



};

