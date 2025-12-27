#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsUser.h"
#include"clsScreen.h"
#include "clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.firstName;
        cout << "\nLastName    : " << User.lastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.email;
        cout << "\nPhone       : " << User.phone;
        cout << "\nUserName    : " << User.userName;
        cout << "\nPassword    : " << User.password;
        cout << "\nPermissions : " << User.permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {

        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t   FindUserScreen                           " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();



        string userName;
        cout << "\nPlease Enter UserName: ";
        userName = clsInputValidate::ReadString();
        while (!clsUser::isUserExist(userName))
        {
            cout << "\nUser is not found, choose another one: ";
            userName = clsInputValidate::ReadString();
        }

        clsUser user1 = clsUser::find(userName);

        if (!user1.isEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(user1);

    }

};
