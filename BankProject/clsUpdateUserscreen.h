#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsUser.h"
#include"clsScreen.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen :protected clsScreen

{
private:


    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.firstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.lastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.permissions = _ReadPermissionsToSet();
    }

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

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::plistClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::paddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pdeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pupdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pfindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::ptranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pmanageUsers;
        }

        return Permissions;

        cout << "\nUser Login List Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::puserLogin;
        }

        cout << "\nCurrency LogScreen? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pCurrencu;
        }

        return Permissions;
    }

public:

    static void ShowUpdateUserScreen()
    {

        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t   UpdateUserScreen                              " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();


        string userName = "";

        cout << "\nPlease Enter User UserName: ";
        userName = clsInputValidate::ReadString();

        while (!clsUser::isUserExist(userName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            userName = clsInputValidate::ReadString();
        }

        clsUser user1 = clsUser::find(userName);

        _PrintUser(user1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(user1);

            clsUser::EnSaveResults SaveResult;

            SaveResult = user1.save();

            switch (SaveResult)
            {
            case  clsUser::EnSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(user1);
                break;
            }
            case clsUser::EnSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

