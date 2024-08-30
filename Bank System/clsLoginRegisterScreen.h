#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;

class clsLoginRegisterScreen:protected clsScreen
{
private:
	static void _PrintLogRegisterRecordLine(clsUser::stLoginRegisterRecord Record)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << Record.DateTime;
		cout << "| " << setw(20) << left << Record.UserName;
		cout << "| " << setw(20) << left << Record.Password;
		cout << "| " << setw(10) << left << Record.Permissions;
	}

public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		system("cls");

		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Titel = "\tLogin Register List Screen";
		string Subtile = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Titel, Subtile);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(35) << "DateTime";
		cout << left << setw(20) << "UserName";
		cout << left << setw(20) << "Password";
		cout << left << setw(10) << "Permissions";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Avalibale In the System";
		else
			for (auto R : vLoginRegisterRecord)
			{
				_PrintLogRegisterRecordLine(R);
				cout << endl;
			}

	}
};

