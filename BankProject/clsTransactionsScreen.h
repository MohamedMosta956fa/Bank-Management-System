#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsScreen.h"
#include"clsTransferScreen.h"
#include"clsTrensferLogScreen.h"
#include <iomanip>

using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTrensferScreen=4, eTrensferLogScreen=5,eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 6? ");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        clsDepositScreen::DepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::WithDrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::showTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::TransferScreen();
    }

    static void _showTransferListScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTrensferScreen:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTrensferLogScreen:
        {

            system("cls");
            _showTransferListScreen();
            _GoBackToTransactionsMenue();
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }



public:


    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::ptranactions))
        {
            return;
        }

        system("cls");
        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t   Transactions Screen                       " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();
 
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer Opertion .\n";
        cout << setw(37) << left << "" << "\t[5] Transfer List Screen .\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};



