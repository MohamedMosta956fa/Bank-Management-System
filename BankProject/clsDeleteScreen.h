#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDeleteUser :protected clsScreen
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
        cout << "\nUser Name   : " << User.userName;
        cout << "\nPassword    : " << User.password;
        cout << "\nPermissions : " << User.permissions;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteUserScreen()
    {
        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t  Delete User Screen                              " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::isUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.deleteUser())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }

};
