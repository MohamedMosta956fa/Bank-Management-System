#pragma once

#include <iostream>
#include "clsBank.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"Header.h"
#include <iomanip>
using namespace std;

class clsTransferScreen:protected clsScreen
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
      
        accountNumber = clsInputValidate ::ReadString();

        while (!clsBank::IsClientFind(accountNumber))
        {
            cout << "\nAccount Number is not found, Enter again: ";
            accountNumber = clsInputValidate::ReadString();
        }
        return accountNumber;
    }


    static float _ReadAmount(clsBank SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.accountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:

    static bool TransferScreen()
    {

        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t  Transfer Screen                              " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();

       
        cout << "\nEnter Account Number to Transfer From : " << endl;
        clsBank sourceClient = clsBank::Find(_ReadAccountNumber());
        _Print(sourceClient);

        
        cout << "\nEnter Account Number to Transfer To : " << endl;
        clsBank destinationClient = clsBank::Find(_ReadAccountNumber());
        _Print(destinationClient);


        float amount = _ReadAmount(sourceClient);


        cout << "Are you sure you want to  Make this Transfer ? (Y/N): ";
        char confirmation;
        cin >> confirmation;

        if (confirmation == 'Y' || confirmation == 'y')
        {
           sourceClient.Transfer(amount, destinationClient, CurrentUser.userName);
            cout << "the Transfer Done Successfully " << endl;
            _Print(sourceClient);
            _Print(destinationClient);
     
            return true;

        }
        else
        {
            cout << "\nthe Opertion is Cancelled\n";
            return false;
        }





    }

  


};

