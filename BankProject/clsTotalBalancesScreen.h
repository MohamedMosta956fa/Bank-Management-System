#pragma once
#include <iostream>
#include "clsBank.h"
#include"clsScreen.h"
#include <iomanip>

class clsTotalBalancesScreen:protected clsScreen
{



private:
   static void _PrintClientBalancesLine(clsBank Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.accountBalance;

    }

public: 


  static  void showTotalBalances()
    {


        vector <clsBank> vclients = clsBank::ShowClients();


        cout << "\n\t\t\t\t\tUser List (" << vclients.size() << ") Client(s).";
        cout << setw(8) << left << "\n__________________________________________________________________________________________________" << endl;
        _DrawDateAndUserName();
        cout << setw(8) << left << "__________________________________________________________________________________________________" << endl;

        
        cout << "_________________________________________\n" << endl;
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;




        if (vclients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBank Client : vclients)
            {

                _PrintClientBalancesLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "the Total Balances is: " << clsBank::GetTotalBalances() << endl;
    }
};

