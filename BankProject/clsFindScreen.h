#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsBank.h"
#include "clsInputValidate.h"
#include"clsScreen.h"
class clsFindScreen:clsScreen
{


    

    private:
        static void _PrintClient(clsBank Client)
        {
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << Client.firstName;
            cout << "\nLastName    : " << Client.lastName;
            cout << "\nFull Name   : " << Client.FullName();
            cout << "\nEmail       : " << Client.email;
            cout << "\nPhone       : " << Client.phone;
            cout << "\nAcc. Number : " << Client.AccountNumber();
            cout << "\nPassword    : " << Client.pinCode;
            cout << "\nBalance     : " << Client.accountBalance;
            cout << "\n___________________\n";

        }

    public:

        static void ShowFindClientScreen()
        {
            if (!CheckAccessRights(clsUser::enPermissions::pfindClient))
            {
                return;
            }
            cout << "\t\t\t\t=================================================" << endl;
            cout << "\t\t\t\t\t\t   FindScreen                                " << endl;
            cout << "\t\t\t\t=================================================" << endl;
            _DrawDateAndUserName();

            cout << "\n---------------------------------------------" << endl;
            cout << "\tFind Client Screen" << endl;
            cout << "---------------------------------------------" << endl;
            string AccountNumber;
            cout << "\nPlease Enter Account Number: ";
            AccountNumber = clsInputValidate::ReadString();
            while (!clsBank::IsClientFind(AccountNumber))
            {
                cout << "\nAccount number is not found, choose another one: ";
                AccountNumber = clsInputValidate::ReadString();
            }

            clsBank Client1 = clsBank::Find(AccountNumber);

            if (!Client1.IsEmpty())
            {
                cout << "\nClient Found :-)\n";
            }
            else
            {
                cout << "\nClient Was not Found :-(\n";
            }

            _PrintClient(Client1);

        }

    };




