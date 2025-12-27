#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen :protected clsScreen
{

private:

    static void _printCurrency(clsCurrency currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << currency.Country();
        cout << "\nCode       : " << currency.CurrencyCode();
        cout << "\nName       : " << currency.CurrencyName();
        cout << "\nRate(1$) = : " << currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _showResults(clsCurrency currency)
    {
        if (!currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _printCurrency(currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void showFindCurrencyScreen()
    {

        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t    Find Currency Screen                   " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();


        cout << "\nFind By: [1] Code or [2] Country ? ";
        short answer = 1;

        cin >> answer;

        if (answer == 1)
        {
            string currencyCode;
            cout << "\nPlease Enter CurrencyCode: ";
            currencyCode = clsInputValidate::ReadString();
            clsCurrency currency = clsCurrency::FindByCode(currencyCode);
            _showResults(currency);
        }
        else
        {
            string country;
            cout << "\nPlease Enter Country Name: ";
            country = clsInputValidate::ReadString();
            clsCurrency currency = clsCurrency::FindByCountry(country);
            _showResults(currency);
        }
    }

};
