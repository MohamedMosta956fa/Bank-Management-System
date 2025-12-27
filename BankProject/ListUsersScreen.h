#pragma once

#include <iostream>
#include "clsUser.h"
#include"clsScreen.h"
#include <iomanip>

class clsListUsersScreen:protected clsScreen

{

private:
    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.userName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.phone;
        cout << "| " << setw(20) << left << User.email;
        cout << "| " << setw(10) << left << User.password;
        cout << "| " << setw(12) << left << User.permissions;

    }

public:

    static void ShowUsersList()
    {
        vector <clsUser> vusers = clsUser::getUsersList();


        cout << "\n\t\t\t\t\tUser List (" << vusers.size() << ") Client(s).";
        cout << setw(8) << left << "\n__________________________________________________________________________________________________"<<endl;
        _DrawDateAndUserName();
        cout << setw(8) << left << "__________________________________________________________________________________________________" << endl;


        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vusers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : vusers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

