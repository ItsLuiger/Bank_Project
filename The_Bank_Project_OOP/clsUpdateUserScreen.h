#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{

	enum enPermissions { eAll = -1, eShow = 1, eAdd = 2, eDel = 4, eUpd = 8, eFind = 16, eTransactions = 32, eManageUsers = 64 , eLoginRegister = 128};

	static short _ReadPermission() {

		short Permission = 0;
		char Answare = 'n';

		cout << "\n\nDo you want to give full access? y/n? ";
		cin >> Answare;

		if (Answare == 'y' || Answare == 'Y') {

			return -1;

		}

		cout << "\n\nDo you want to give Access to : ";
		cout << "\n\nShow Client List? y/n? : ";
		cin >> Answare;
		if (Answare == 'y' || Answare == 'Y') {

			Permission += enPermissions::eShow;
		}

		cout << "\n\nAdd New Client? y/n? : ";
		cin >> Answare;
		if (Answare == 'y' || Answare == 'Y') {

			Permission += enPermissions::eAdd;
		}

		cout << "\n\nDelete Client? y/n? : ";
		cin >> Answare;
		if (Answare == 'y' || Answare == 'Y') {

			Permission += enPermissions::eDel;
		}

		cout << "\n\nUpdate Client? y/n? : ";
		cin >> Answare;
		if (Answare == 'y' || Answare == 'Y') {

			Permission += enPermissions::eUpd;
		}

		cout << "\n\nFind Client? y/n? : ";
		cin >> Answare;
		if (Answare == 'y' || Answare == 'Y') {

			Permission += enPermissions::eFind;
		}

		cout << "\n\nTransactions? y/n? : ";
		cin >> Answare;
		if (Answare == 'y' || Answare == 'Y') {

			Permission += enPermissions::eTransactions;
		}

		cout << "\n\nManage Users? y/n? : ";
		cin >> Answare;
		if (Answare == 'y' || Answare == 'Y') {

			Permission += enPermissions::eManageUsers;
		}

		cout << "\n\nSee Login Screeen? y/n? : ";
		cin >> Answare;
		if (Answare == 'y' || Answare == 'Y') {

			Permission += enPermissions::eLoginRegister;
		}

		return Permission;
	}

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

	static void _ReadUserInformations(clsUser& User) {

		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\n\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\n\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\n\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\n\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\n\nEnter Permission:";
		User.Permissions = _ReadPermission();

	}

public : 

	static void ShowUpdateUserScreen() {

		clsScreen::_DrawScreenHeader("Update User Screen");

		cout << "\n\nPlease Enter User UserName : ";
		string UserName = clsInputValidate::ReadString();

		while (!(clsUser::IsUserExist(UserName))) {

			cout << "\nThe User is not found, please enter another username : ";

			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\nAre you sure you want to update this user y/n? ";
		char Answare = clsInputValidate::CheckAnsware();

		if (Answare == 'Y' || Answare == 'y') {

			cout << "\n\nUpdate User Info: ";
			cout << "\n________________________\n";


			_ReadUserInformations(User);
			
			clsUser::enSaveResults SaveResult;

			SaveResult = User.Save();

			switch (SaveResult)
			{
			case  clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUser Updated Successfully :-)\n";
				_PrintUser(User);
				break;
			}
			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}
			case clsUser::enSaveResults::svFaildUserExists:
			{
				cout << "\nError account was not saved because User Name is used!\n";
				break;

			}
			}


		}
	}

};

