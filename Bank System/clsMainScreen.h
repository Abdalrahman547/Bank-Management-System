#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"Global.h"
using namespace std;

class clsMainScreen:protected clsScreen
{
private:

	enum enMainMenueOptions {
		eListClients =1, eAddNewClient =2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLohinRegister = 8, eExit = 9
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what dou you want to do? [1 to 9]? ";

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 9);

		return Choice;
	}

	static void _GoBackToMainMenueScreen()
	{
		cout << setw(37) << left << "\n\tPress any key to go to back to Main Menue...\n";

		system("pause>0");

		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClienScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();

	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionMenue()
	{
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//it will back to main function as a empty user


		// MyQusetion:
		// I mean i wanted to put => clsLoginSreen::ShowLoginScreen() here
		// to call login Screen again
	}

	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case clsMainScreen::eListClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenueScreen();
			break;

		case clsMainScreen::eAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenueScreen();
			break;

		case clsMainScreen::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenueScreen();
			break;

		case clsMainScreen::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenueScreen();
			break;

		case clsMainScreen::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenueScreen();
			break;

		case clsMainScreen::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionMenue();
			_GoBackToMainMenueScreen();
			break;

		case clsMainScreen::eManageUsers:
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenueScreen();
			break;

		case clsMainScreen::eLohinRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenueScreen();
			break;

		case clsMainScreen::eExit:
			system("cls");
			_Logout();
			break;
		}
	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

	}

};

