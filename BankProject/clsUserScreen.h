#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"


class clsUserScreen :protected clsScreen
{

private:

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.dateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.userName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.permissions;
    }

public:

    static void ShowLoginRegisterScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::puserLogin))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vloginRegisterRecord = clsUser::GetLoginRegisterList();


        cout << "\n\t\t\t\t\tUser List (" << vloginRegisterRecord.size() << ") Client(s).";
        cout << setw(8) << left << "\n__________________________________________________________________________________________________" << endl;
        _DrawDateAndUserName();
        cout << setw(8) << left << "__________________________________________________________________________________________________" << endl;



        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vloginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vloginRegisterRecord)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};