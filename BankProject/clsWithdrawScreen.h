#pragma once
#include <iostream>
#include "clsBank.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
class clsWithdrawScreen:protected clsScreen
{
private:

    static void _Print(clsBank client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nBalance     : " << client.accountBalance;
        cout << "\n___________________\n";

    }



    static string _ReadAccountNumber()
    {
        string accountNumber = "";
        cout << "\nEnter Account Number to deducted Amount : " << endl;
        accountNumber = clsInputValidate::ReadString();
        return accountNumber;
    }
public:
    static bool WithDrawScreen()
    {


        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t  Withdraw Screen                              " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();

        string accountNumber = "";
        accountNumber = _ReadAccountNumber();


        while (!clsBank::IsClientFind(accountNumber))
        {
            cout << "\nAccount Number is not found, Enter again: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBank Client = clsBank::Find(accountNumber);
        _Print(Client);

        float amount = 0;
        cout << "Please Enter Amount You Want To Withdraw" << endl;
        amount = clsInputValidate::ReadFloatNumber();


        while (amount <= 0 || amount>Client.accountBalance)
        {
            cout << "Please Enter Vaild Amount Number" << endl;
            amount = clsInputValidate::ReadFloatNumber();

        }


        cout << "Are you sure you want to deducted this Amount ? (Y/N): ";
        char confirmation;
        cin >> confirmation;

        if (confirmation == 'Y' || confirmation == 'y')
        {

            cout << "this Amount was deducted" << endl;
            Client.Withdraw(amount);
            cout << "The Account Balance After Withdraw " << Client.accountBalance << endl;

            return true;

        }
        else
        {
            cout << "\nthe Opertion is Cancelled\n";
            return false;
        }


        
    }

};