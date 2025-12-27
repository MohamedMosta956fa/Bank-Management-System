#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen

{
private:

    static float _readAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float amount = 0;

        amount = clsInputValidate::ReadFloatNumber();
        return amount;
    }

    static clsCurrency _getCurrency(string message)
    {

        string currencyCode;
        cout << message << endl;

        currencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(currencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            currencyCode = clsInputValidate::ReadString();
        }

        clsCurrency currency = clsCurrency::FindByCode(currencyCode);
        return currency;

    }


    static  void _printCurrencyCard(clsCurrency currency, string title = "Currency Card:")
    {

        cout << "\n" << title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << currency.Country();
        cout << "\nCode          : " << currency.CurrencyCode();
        cout << "\nName          : " << currency.CurrencyName();
        cout << "\nRate(1$) =    : " << currency.Rate();
        cout << "\n_____________________________\n\n";

    }

    static void _printCalculationsResults(float amount, clsCurrency currency1, clsCurrency currency2)
    {

        _printCurrencyCard(currency1, "Convert From:");

        float amountInUSD = currency1.ConvertToUSD(amount);

        cout << amount << " " << currency1.CurrencyCode()
            << " = " << amountInUSD << " USD\n";

        if (currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _printCurrencyCard(currency2, "To:");

        float amountInCurrrency2 = currency1.ConvertToOtherCurrency(amount, currency2);

        cout << amount << " " << currency1.CurrencyCode()
            << " = " << amountInCurrrency2 << " " << currency2.CurrencyCode();

    }


public:

    static void showCurrencyCalculatorScreen()
    {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");
            cout << "\t\t\t\t=================================================" << endl;
            cout << "\t\t\t\t\t\t     Currency Calculator Screen                  " << endl;
            cout << "\t\t\t\t=================================================" << endl;
            _DrawDateAndUserName();


            clsCurrency currencyFrom = _getCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency currencyTo = _getCurrency("\nPlease Enter Currency2 Code: ");
            float amount = _readAmount();

            _printCalculationsResults(amount, currencyFrom, currencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;

        }


    }
};