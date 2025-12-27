#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRateScreen :protected clsScreen

{
private:

    static float _readRate()
    {
        cout << "\nEnter New Rate: ";
        float newRate = 0;

        newRate = clsInputValidate::ReadFloatNumber();
        return newRate;
    }

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

public:

    static void showUpdateCurrencyRateScreen()
    {

        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t    Update Currency Screen                   " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();

        string currencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        currencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(currencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            currencyCode = clsInputValidate::ReadString();
        }

        clsCurrency currency = clsCurrency::FindByCode(currencyCode);
        _printCurrency(currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            currency.UpdateRate(_readRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _printCurrency(currency);


        }

    }
};