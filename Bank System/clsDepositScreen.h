#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;


class clsDepositScreen:protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\tDeposit Screen");

        cout << "\nEnter AccountNumber: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient CLient1 = clsBankClient::Find(AccountNumber);
        _PrintClient(CLient1);

        cout << "\nPlease enter deposit amount? ";
        double Amount = clsInputValidate::ReadDblNumber();

        char ans = 'N';
        cout << "\nAre you sure you want to perform this transaction? Y/N? ";
        cin >> ans;

        if (ans == 'Y' || ans == 'y')
        {
            CLient1.Deposit(Amount);
            cout << "\nAmount Deposit Successfully.\n";
            cout << "\New Balance Is: " << CLient1.AccountBalance;
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};

