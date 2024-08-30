#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
using namespace std;


class clsDeleteClientScreen:protected clsScreen
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

    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::pDeleteClient))
        {
            return;
        }

        _DrawScreenHeader("\tDelete Client Screen");

        cout << "\nEnter AccountNumber: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre you sure to delete this client? Y/N? ";

        char Answer = 'N';

        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Delete();

            cout << "\nClient Deleted Successfully :-)\n";

            _PrintClient(Client1);
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }

};

