#pragma once
#include <iostream>
#include "clsBank.h"
#include"clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddscreen : protected clsScreen
{
private:
    static  void _ReadClientInfo(clsBank& client)
    {
        cout << "\nEnter FirstName: ";
        client.firstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        client.lastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        client.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        client.phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        client.pinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        client.accountBalance = clsInputValidate::ReadFloatNumber();
    }
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

    static void ADDClient()
    {

        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t  Delete User Screen                              " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();

        if (!CheckAccessRights(clsUser::enPermissions::paddNewClient))
        {
            return;
        }

        string accountNumber = "";
        cout << "\nEnter Account Number to Add Client: ";
        accountNumber = clsInputValidate::ReadString();
        while (clsBank::IsClientFind(accountNumber))
        {
            cout << "\nAccount Number already exists, Enter another Account Number: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBank client1 = clsBank::GetAddNewClientObject(accountNumber);
        cout << "\nAdding New Client Info: \n";
        _ReadClientInfo(client1);
        clsBank::enSaveResults saveResult;
        saveResult = client1.Save();

        switch (saveResult)
        {

        case clsBank::enSaveResults::svSucceeded:
        {
            cout << "\nClient Added Successfully\n";
            _Print(client1);
		

            break;
        }
        case clsBank::enSaveResults::svFailedAccountNumberExists:
        {
            cout << "\nAccount Number already exists, failed to add new client\n";
            break;
        }
        case clsBank::enSaveResults::svEmptyObject:
        {
            cout << "\nClient is empty, failed to add new client\n";
            break;
        }



        }



    }
};

