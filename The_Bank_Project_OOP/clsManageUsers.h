#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUsersListScreen.h";
#include "clsAddNewUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";
#include "clsGlobal.h";

using namespace std;

class clsManageUsers : protected clsScreen
{
	
	enum enManageUsers { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6};

	static void _GoBackToManageUsersMenue() {

		cout << "\n\n\tPress Any Key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _ShowUsers() {

		clsUsersListScreen::ShowListUsersScreen();

	}

	static void _AddNewUser() {

		clsAddNewUserScreen::ShowAddNewUserScreen();
	
	}

	static void _DeleteUser() {


		clsDeleteUserScreen::ShowDeleteUserScreen();


	}

	static void _UpdateUser() {

		clsUpdateUserScreen::ShowUpdateUserScreen();


	}

	static void _FindUser() {

		clsFindUserScreen::ShowFindUserSccreen();


	}

	static void _MainMenue() {

		cout << "\nDor T9awed mn hna .";

	}

	static short _ReadShowManageUsersMenueOption() {

		cout << "Choose What do you want to do? [1 to 6] ? ";
		short Choose = clsInputValidate::ReadIntNumberBetween(1, 6, "Choose What do you want to do? [1 to 6] ? ");

		return Choose;
	}

	static void _PerfromShowManageUsersMenueOption(enManageUsers ShowManageUsersMenue) {

		switch (ShowManageUsersMenue) {


		case enManageUsers::eListUsers:

			system("cls");
			_ShowUsers();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsers::eAddNewUser:

			system("cls");
			_AddNewUser();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsers::eUpdateUser:

			system("cls");
			_UpdateUser();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsers::eDeleteUser:

			system("cls");
			_DeleteUser();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsers::eFindUser:

			system("cls");
			_FindUser();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsers::eMainMenue:

			system("cls");
			_MainMenue();
			_GoBackToManageUsersMenue();
			break;
		}


	}

public : 

	static void ShowManageUsersScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::eManageUsers)) {

			return;
		}

		system("cls");

		clsScreen::_DrawScreenHeader("Manage Users Screen");


		cout << "===============================================\n";
		cout << "                Manage Users Screen\n";
		cout << "===============================================\n";
		cout << "        [1] List Users.\n";
		cout << "        [2] Add New User.\n";
		cout << "        [3] Delete User.\n";
		cout << "        [4] Update User.\n";
		cout << "        [5] Find User.\n";
		cout << "        [6] Main Menue.\n";
		cout << "===============================================\n";

		_PerfromShowManageUsersMenueOption((enManageUsers)_ReadShowManageUsersMenueOption());

	}

};

