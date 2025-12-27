#pragma once
#include <iostream>
#include "clsBank.h"
#include "clsInputValidate.h"
#include"clsScreen.h"
#include <iomanip>

class clsDelateScreen:protected clsScreen
{
private:

    static void _Print(clsBank client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.firstName;
        cout << "\nLastName    : " << client.lastName;
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.email;
        cout << "\nPhone       : " << client.phone;
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.pinCode;
        cout << "\nBalance     : " << client.accountBalance;
        cout << "\n___________________\n";

    }
public:


    static void DeleteClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pdeleteClient))
        {
            return;
        }

        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t  Delete User Screen                              " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();

        string accountNumber = "";
        cout << "\nEnter Account Number to Delete Client: ";
        accountNumber = clsInputValidate::ReadString();
        while (!clsBank::IsClientFind(accountNumber))
        {
            cout << "\nAccount Number is not found, Enter again: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBank Client = clsBank::Find(accountNumber);
		  _Print(Client);

        cout << "Are you sure you want to delete this client? (Y/N): ";
        char confirmation;
        cin >> confirmation;

        if (confirmation == 'Y' || confirmation == 'y')
        {
            if (Client.Delete())
            {

                cout << "\nClient Deleted Successfully\n";
				_Print(Client);
            }
            else
            {
                cout << "\nFailed to Delete Client\n";
            }

        }
        else
        {
            cout << "\nDeletion Cancelled\n";
        }

    }
};

