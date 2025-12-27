#pragma once
#include <iostream>
#include "clsString.h"
#include"clsPerson.h"
#include<string>
#include"clsDate.h"
#include<vector>
#include"clsUtil.h"
#include<fstream>
using namespace std;

class clsBank : public clsPerson
{

private:
    enum enMode { emptyMode = 0, updateMode = 1, addMode = 2, deleteMode = 3 };

    string _accountNumber;
    string _pinCode;
    double _accountBalance;
    enMode _mode;
    bool _markedForDelete = false;


    static clsBank _convertLineToObject(string line, string delim = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(line, delim);



        return clsBank(enMode::updateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    struct stTrnsferLogRecord;

    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord trnsferLogRecord;

        vector <string> vtrnsferLogRecordLine = clsString::Split(Line, Seperator);
        trnsferLogRecord.dateTime = vtrnsferLogRecordLine[0];
        trnsferLogRecord.sourceAccountNumber = vtrnsferLogRecordLine[1];
        trnsferLogRecord.destinationAccountNumber = vtrnsferLogRecordLine[2];
        trnsferLogRecord.amount = stod(vtrnsferLogRecordLine[3]);
        trnsferLogRecord.srcbalanceAfter = stod(vtrnsferLogRecordLine[4]);
        trnsferLogRecord.destbalanceAfter = stod(vtrnsferLogRecordLine[5]);
        trnsferLogRecord.userName = vtrnsferLogRecordLine[6];

        return trnsferLogRecord;

    }


    static string _convertObjectToLine(clsBank client)
    {
        string delim = "#//#";
        string line = "";
        line += client.firstName + delim;
        line += client.lastName + delim;
        line += client.email + delim;
        line += client.phone + delim;
        line += client.AccountNumber() + delim;
        line += client.pinCode + delim;
        line += to_string(client.accountBalance); 
        return line;
    }

     string _convertObjectTrensferToLine(float amount, clsBank destinationClient, string userName, string delim= "#//#")
    {
        string transferLogRecord = "";
        transferLogRecord += clsDate::GetSystemDateTimeString() + delim;
        transferLogRecord += AccountNumber() + delim;
        transferLogRecord += destinationClient.AccountNumber() + delim;
        transferLogRecord += to_string(amount) + delim;
        transferLogRecord += to_string(accountBalance) + delim;
        transferLogRecord += to_string(destinationClient.accountBalance) + delim;
        transferLogRecord += userName;

        return transferLogRecord;
    }


    static clsBank _getEmptyClientObject()
    {
        return clsBank(enMode::emptyMode, "", "", "", "", "", "", 0);
    }



    static vector<clsBank> _loadAllClientsDataFromFile()
    {
        vector<clsBank> vClients;
        fstream myFile;
        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsBank client = _convertLineToObject(line);
                vClients.push_back(client);
            }
            myFile.close();
        }
        return vClients;
    }


    void _saveAllClientsDataToFile(vector<clsBank> vClients)
    {
        fstream myFile;
        myFile.open("Clients.txt", ios::out);
        if (myFile.is_open())
        {
            for (clsBank client : vClients)
            {
                if (client.IsMarkedForDelete() == false)
                {
                    string line = _convertObjectToLine(client);
                    myFile << line << endl;
                }

            }

            myFile.close();
        }

    }


    void _updateClient()
    {

        vector<clsBank> vClients;
        vClients = _loadAllClientsDataFromFile();
        for (clsBank& client : vClients)
        {
            if (client.AccountNumber() == AccountNumber())
            {

                client = *this;
                break;

            }
        }

        _saveAllClientsDataToFile(vClients);
    }

    void _addNew()
    {
        _addDataLineToFile(_convertObjectToLine(*this));
    }

    void _addDataLineToFile(string dataLine)
    {
        fstream myFile;
        myFile.open("Clients.txt", ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << dataLine << endl;
            myFile.close();
        }
    }
    

    void _RegisterTrensferLogFile(float amount, clsBank DestinationClient, string userName)
    {
        string dataLine = _convertObjectTrensferToLine(amount, DestinationClient, userName);
        fstream myFile;
        myFile.open("TransferLog.txt", ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << dataLine << endl;
            myFile.close();
        }
    }



public:

    struct stTrnsferLogRecord
    {
        string dateTime;
        string sourceAccountNumber;
        string destinationAccountNumber;
        float amount;
        float srcbalanceAfter;
        float destbalanceAfter;
        string userName;

    };


    clsBank(enMode mode, string firstName, string lastName,
        string email, string phone, string accountNumber, string pinCode,
        double accountBalance) :
        clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _accountNumber = accountNumber;
        _pinCode = pinCode;
        _accountBalance = accountBalance;
    }


    bool IsEmpty()
    {
        return (_mode == enMode::emptyMode);
    }

    

    bool IsMarkedForDelete()
    {
        return _markedForDelete;
    }


    string AccountNumber()
    {
        return _accountNumber;
    }


    void SetPinCode(string pinCode)
    {
        _pinCode = pinCode;
    }

    string GetPinCode()
    {
        return _pinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string pinCode;

    void SetAccountBalance(float accountBalance)
    {
        _accountBalance = accountBalance;
    }

    float GetAccountBalance()
    {
        return _accountBalance;
    }
    
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float accountBalance;


   

    static clsBank Find(string accountNumber)
    {
        fstream myFile;
        myFile.open("Clients.txt", ios::in);

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsBank client = _convertLineToObject(line);
                if (client.AccountNumber() == accountNumber)
                {
                    myFile.close();
                    return client;
                }
            }
            myFile.close();
        }
        return _getEmptyClientObject();
    }


    static clsBank Find(string accountNumber, string pinCode)
    {
        fstream myFile;
        myFile.open("Clients.txt", ios::in);

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsBank client = _convertLineToObject(line);
                if (client.AccountNumber() == accountNumber && client.pinCode == pinCode)
                {
                    myFile.close();
                    return client;
                }
            }
            myFile.close();
        }
        return _getEmptyClientObject();
    }


    static bool IsClientFind(string accountNumber)
    {
        clsBank client = clsBank::Find(accountNumber);
        return (!client.IsEmpty());
    }


    bool Delete()
    {
        vector <clsBank> vClients = _loadAllClientsDataFromFile();

        for (clsBank& client : vClients)
        {
            if (client.AccountNumber() == AccountNumber())
            {
                client._markedForDelete = true;
                _saveAllClientsDataToFile(vClients);
                *this = _getEmptyClientObject();
                return true;
            }
        }
        return false;
    }


    enum enSaveResults { svEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2 };

    enSaveResults Save()
    {
        switch (_mode)
        {

        case enMode::emptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svEmptyObject;
            }
            break;
        }
        case enMode::updateMode:
        {
            _updateClient();
            return enSaveResults::svSucceeded;
            break;
        }

        case enMode::addMode:
        {
            if (IsClientFind(AccountNumber()))
            {
                return enSaveResults::svFailedAccountNumberExists;
            }
            else
            {
                _addNew();
                return enSaveResults::svSucceeded;
            }
            break;
        }
        }
        return enSaveResults::svEmptyObject;
    }

    static clsBank GetAddNewClientObject(string accountNumber)
    {
        return clsBank(enMode::addMode, "", "",
            "", "", accountNumber, "",
            0);
    }

    static vector < clsBank> ShowClients()
    {
        return _loadAllClientsDataFromFile();
    }


    static float GetTotalBalances()
    {
        vector < clsBank> vClients = _loadAllClientsDataFromFile();
        float totalBalances = 0;
        for (clsBank client : vClients)
        {
            totalBalances += client.accountBalance;
        }

        return totalBalances;
    }

    void Deposit(float amount)
    {
        accountBalance += amount;
        Save();
    }

    void Withdraw(float amount)
    {
        accountBalance -= amount;
        Save();
    }

    bool Transfer(float amount, clsBank& destinationClient, string userName)
    {
        if (amount > accountBalance)
        {
            return false;
        }

        Withdraw(amount);
        destinationClient.Deposit(amount);
        _RegisterTrensferLogFile(amount, destinationClient, userName);
        return true;
    }


    static  vector <stTrnsferLogRecord> GetTransfersLogList()
    {
        vector <stTrnsferLogRecord> vtransferLogRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string line;

            stTrnsferLogRecord transferRecord;

            while (getline(MyFile, line))
            {

                transferRecord = _ConvertTransferLogLineToRecord(line);

                vtransferLogRecord.push_back(transferRecord);

            }

            MyFile.close();

        }

        return vtransferLogRecord;

    }

};