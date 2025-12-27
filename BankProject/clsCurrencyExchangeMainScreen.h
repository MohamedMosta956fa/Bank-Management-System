#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include <iomanip>

using namespace std;

class clsCurrencyExchangeMainScreen :protected clsScreen
{

private:
    enum enCurrenciesMainMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenu = 5
    };

    static short readCurrenciesMainMenuOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return choice;
    }

    static void _goBackToCurrenciesMenu()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");
        showCurrenciesMenu();
    }

    static void _showCurrenciesListScreen()
    {
        clsCurrenciesListScreen::showCurrenciesListScreen();

    }

    static void _showFindCurrencyScreen()
    {
        clsFindCurrencyScreen::showFindCurrencyScreen();

    }

    static void _showUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRateScreen::showUpdateCurrencyRateScreen();
    }

    static void _showCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::showCurrencyCalculatorScreen();

    }

    static void _performCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions currenciesMainMenueOptions)
    {

        switch (currenciesMainMenueOptions)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _showCurrenciesListScreen();
            _goBackToCurrenciesMenu();
            break;
        }

        case enCurrenciesMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _showFindCurrencyScreen();
            _goBackToCurrenciesMenu();
            break;
        }

        case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
        {
            system("cls");
            _showUpdateCurrencyRateScreen();
            _goBackToCurrenciesMenu();
            break;
        }

        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _showCurrencyCalculatorScreen();
            _goBackToCurrenciesMenu();
            break;
        }

        case enCurrenciesMainMenueOptions::eMainMenu:
        {
        }
        }

    }

public:

    static void showCurrenciesMenu()
    {


        system("cls");

        if (!CheckAccessRights(clsUser::enPermissions::pCurrencu))
        {
            return;
        }
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Currency screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _DrawDateAndUserName();
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)readCurrenciesMainMenuOptions());
    }

};