#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "Global.h"
using namespace std;

class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		string Username, Password;

		bool LoginFaild = false;
		short FaildLoginCount = 0;

		do
		{

			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvalid Username/Password!\n";
				cout << "You have " << (3 - FaildLoginCount) << " Trial(s) to login.\n\n";
			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYou are locked after 3 faild trails.\n\n";
				return false;
			}

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenue();

	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");

		return _Login();
	}

};

