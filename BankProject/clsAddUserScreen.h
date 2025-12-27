#pragma once
#include"clsUser.h"
#include"clsInputValidate.h"
#include"string.h"
#include"clsScreen.h"
#include <iomanip>
class clsAddUserScreen:protected clsScreen
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

        static void ShowAddNewUserScreen()
        {

            cout << "\t\t\t\t=================================================" << endl;
            cout << "\t\t\t\t\t\t  Add User Screen                              " << endl;
            cout << "\t\t\t\t=================================================" << endl;
            _DrawDateAndUserName();
            string UserName = "";

            cout << "\nPlease Enter UserName: ";
            UserName = clsInputValidate::ReadString();
            while (clsUser::isUserExist(UserName))
            {
                cout << "\nUserName Is Already Used, Choose another one: ";
                UserName = clsInputValidate::ReadString();
            }

            clsUser NewUser = clsUser::getAddNewUserObject(UserName);

            _ReadUserInfo(NewUser);

            clsUser::EnSaveResults SaveResult;

            SaveResult = NewUser.save();

            switch (SaveResult)
            {
            case  clsUser::EnSaveResults::svSucceeded:
            {
                cout << "\nUser Addeded Successfully :-)\n";
                _PrintUser(NewUser);
                break;
            }
            case clsUser::EnSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }
            case clsUser::EnSaveResults::svFaildUserExists:
            {
                cout << "\nError User was not saved because UserName is used!\n";
                break;

            }
            }
        }



    };

       



