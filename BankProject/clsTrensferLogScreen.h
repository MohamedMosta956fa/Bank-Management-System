#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBank.h"


class clsTransferLogScreen :protected clsScreen
{

private:

    static void PrintTransferLogRecordLine(clsBank::stTrnsferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.dateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.sourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.destinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.amount;
        cout << "| " << setw(10) << left << TransferLogRecord.srcbalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.destbalanceAfter;
        cout << "| " << setw(8) << left << TransferLogRecord.userName;


    }

public:

    static void ShowTransferLogScreen()
    {


        vector <clsBank::stTrnsferLogRecord> vtransferLogRecord = clsBank::GetTransfersLogList();
        cout << "\n\t\t\t\t\tTransfer List (" << vtransferLogRecord.size() << ") Client(s).";
        cout << setw(8) << left << "\n__________________________________________________________________________________________________" << endl;
        _DrawDateAndUserName();
        cout << setw(8) << left << "__________________________________________________________________________________________________" << endl;


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vtransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBank::stTrnsferLogRecord Record : vtransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};


