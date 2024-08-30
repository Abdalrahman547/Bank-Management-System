#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsTransferScreen:protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccounNumber(string Type)
	{
		string AccountNumber;

		cout << "\nPlease Enter Account Number to Transfer " << Type << ": ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourseClient)
	{
		cout << "\nPlease Enter Transfer Amount: Not Exceeded (" << SourseClient.AccountBalance << ")? ";
		double Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourseClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the avalible Balance, Enter another Amount Not Exceeded (" << SourseClient.AccountBalance << ")? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		system("cls");

		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourseClient = clsBankClient::Find(_ReadAccounNumber("From"));

		_PrintClient(SourseClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccounNumber("To"));

		_PrintClient(DestinationClient);

		double Amount = _ReadAmount(SourseClient);

		char ans = 'N';

		cout << "\nAre you sure you want to perform this operation? Y/N? ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y')
		{
			if (SourseClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done siccessfully";
			}
			else
				cout << "\nTransfer Faild";
		}

		_PrintClient(SourseClient);
		_PrintClient(DestinationClient);

	}
};

