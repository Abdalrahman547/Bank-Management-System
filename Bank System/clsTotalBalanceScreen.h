#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"
using namespace std;

class clsTotalBalanceScreen : protected clsScreen
{
private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }


public:

    static void ShowTotalBalanceScreen()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        _DrawScreenHeader("\tTotal Balances Screen");

        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << setw(40) << left << "Client Name";
        cout << "| " << setw(12) << left << "Balance";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Avilable In the System!";
        else
        {
            for (auto C : vClients)
            {
                _PrintClientRecordBalanceLine(C);
                cout << "\n";
            }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout << "\t\t\t\t\t\t    Total Balances = " << TotalBalances << endl;
            cout << "\t\t\t\t\t\t    (" << clsUtil::NumberToText(TotalBalances) << ")\n";

        }
    }

};

