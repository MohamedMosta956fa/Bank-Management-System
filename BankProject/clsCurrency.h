#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class clsCurrency
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _mode;

    string _country;
    string _currencyCode;
    string _currencyName;
    float _rate;

    static clsCurrency _convertLineToCurrencyObject(string line, string separator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(line, separator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
            stod(vCurrencyData[3]));

    }

    static string _convertCurrencyObjectToLine(clsCurrency currency, string separator = "#//#")
    {

        string stCurrencyRecord = "";
        stCurrencyRecord += currency.Country() + separator;
        stCurrencyRecord += currency.CurrencyCode() + separator;
        stCurrencyRecord += currency.CurrencyName() + separator;

        stCurrencyRecord += to_string(currency.Rate());

        return stCurrencyRecord;

    }

    static  vector <clsCurrency> _loadCurrenciesDataFromFile()
    {

        vector <clsCurrency> vCurrencies;

        fstream myFile;
        myFile.open("Currencies.txt", ios::in);

        if (myFile.is_open())
        {

            string line;

            while (getline(myFile, line))
            {

                clsCurrency currency = _convertLineToCurrencyObject(line);

                vCurrencies.push_back(currency);
            }

            myFile.close();

        }

        return vCurrencies;

    }

    static void _saveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
    {

        fstream myFile;
        myFile.open("Currencies.txt", ios::out);

        string dataLine;

        if (myFile.is_open())
        {

            for (clsCurrency C : vCurrencies)
            {
                dataLine = _convertCurrencyObjectToLine(C);
                myFile << dataLine << endl;
            }

            myFile.close();

        }

    }

    void _update()
    {
        vector <clsCurrency> _vCurrencies;
        _vCurrencies = _loadCurrenciesDataFromFile();

        for (clsCurrency& C : _vCurrencies)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }

        }

        _saveCurrencyDataToFile(_vCurrencies);

    }

    static clsCurrency _getEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:

    clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate)
    {
        _mode = mode;
        _country = country;
        _currencyCode = currencyCode;
        _currencyName = currencyName;
        _rate = rate;
    }

    static vector <clsCurrency> GetAllUSDRates()
    {

        return _loadCurrenciesDataFromFile();

    }

    bool IsEmpty()
    {
        return (_mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _country;
    }

    string CurrencyCode()
    {
        return _currencyCode;
    }

    string CurrencyName()
    {
        return _currencyName;
    }

    void UpdateRate(float newRate)
    {
        _rate = newRate;
        _update();
    }

    float Rate()
    {
        return _rate;
    }


    static   clsCurrency FindByCode(string currencyCode)
    {

        currencyCode = clsString::UpperAllString(currencyCode);

        fstream myFile;
        myFile.open("Currencies.txt", ios::in);

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsCurrency currency = _convertLineToCurrencyObject(line);
                if (currency.CurrencyCode() == currencyCode)
                {
                    myFile.close();
                    return currency;
                }
            }

            myFile.close();

        }

        return _getEmptyCurrencyObject();

    }

    static   clsCurrency FindByCountry(string country)
    {
        country = clsString::UpperAllString(country);

        fstream myFile;
        myFile.open("Currencies.txt", ios::in);

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsCurrency currency = _convertLineToCurrencyObject(line);
                if (clsString::UpperAllString(currency.Country()) == country)
                {
                    myFile.close();
                    return currency;
                }

            }

            myFile.close();

        }

        return _getEmptyCurrencyObject();

    }

    static bool IsCurrencyExist(string currencyCode)
    {
        clsCurrency c1 = clsCurrency::FindByCode(currencyCode);
        return (!c1.IsEmpty());

    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _loadCurrenciesDataFromFile();
    }

    float ConvertToUSD(float amount)
    {
        return (float)(amount / Rate());
    }

    float ConvertToOtherCurrency(float amount, clsCurrency currency2)
    {
        float AmountInUSD = ConvertToUSD(amount);

        if (currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * currency2.Rate());

    }

};