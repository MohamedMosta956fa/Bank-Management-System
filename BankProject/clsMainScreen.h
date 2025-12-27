#pragma once
#include <iostream>
#include "clsClientListScreen.h"
#include "clsInputValidate.h"
#include"clsAddscreen.h"
#include"clsUpdateScreen.h"
#include"clsFindScreen.h"
#include"clsDelateScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"Header.h"
#include"clsScreen.h"
#include"clsUserScreen.h"
#include"clsCurrencyExchangeMainScreen.h"
#include <iomanip>


using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7,eUserLogin=8, eCurrencyScreen=9 ,eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddscreen::ADDClient();

    }

    static void _ShowDeleteClientScreen()
    {
        
		clsDelateScreen::DeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
		clsUpdateScreen::UpdateClient();

    }

    static void _ShowFindClientScreen()
    {
		clsFindScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowUserScreenMenue()
    {
        clsUserScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyScreen()
    {
        clsCurrencyExchangeMainScreen::showCurrenciesMenu();
    
    }

    static void _ShowEndScreen()
    {
        CurrentUser = clsUser::find("", "");
    }


    static void _PerfromMainMenueOption(enMainMenueOptions mainMenueOption)
    {
        switch (mainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;


        case enMainMenueOptions ::eUserLogin:
               system("cls");
             _ShowUserScreenMenue();
             _GoBackToMainMenue();
        case enMainMenueOptions::eCurrencyScreen:
                 system("cls");
                 _ShowCurrencyScreen();
                 _GoBackToMainMenue();

        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
           
           

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        clsScreen::_DrawDateAndUserName();
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Show Login Secreen.\n";
        cout << setw(37) << left << "" << "\t[9] Show Currency Secreen.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

