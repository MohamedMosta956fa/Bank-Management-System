#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include <vector>

using namespace std;

class clsCurrenciesListScreen :protected clsScreen
{

private:
    static void _printCurrencyRecordLine(clsCurrency currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << currency.Country();
        cout << "| " << setw(8) << left << currency.CurrencyCode();
        cout << "| " << setw(45) << left << currency.CurrencyName();
        cout << "| " << setw(10) << left << currency.Rate();

    }

public:


    static void showCurrenciesListScreen()
    {


        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t    Currencies List Screen                   " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();

      
      cout<< "\t    (" + to_string(vCurrencies.size()) + ") Currency."<<endl;

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency currency : vCurrencies)
            {

                _printCurrencyRecordLine(currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

    }

};