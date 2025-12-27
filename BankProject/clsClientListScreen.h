#pragma once
#include <iostream>
#include "clsBank.h"
#include"clsScreen.h"
#include <iomanip>


using namespace std;
class clsClientListScreen:protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBank client)
    {
        cout << "| " << setw(15) << left << client.AccountNumber();
        cout << "| " << setw(20) << left << client.FullName();
        cout << "| " << setw(12) << left << client.phone;
        cout << "| " << setw(20) << left << client.email;
        cout << "| " << setw(10) << left << client.pinCode;
        cout << "| " << setw(12) << left << client.accountBalance;

    }
public :
    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::plistClients))
        {
            return;
        }

        vector <clsBank> vclients = clsBank::ShowClients();


        cout << "\n\t\t\t\t\tUser List (" << vclients.size() << ") Client(s).";
        cout << setw(8) << left << "\n__________________________________________________________________________________________________" << endl;
        _DrawDateAndUserName();
        cout << setw(8) << left << "__________________________________________________________________________________________________" << endl;


        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vclients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBank client : vclients)
            {

                _PrintClientRecordLine(client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};

