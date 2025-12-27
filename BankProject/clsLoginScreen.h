#pragma once

#include <iostream>
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Header.h"

class clsLoginScreen:protected clsScreen 

{ 

private:

    static  bool _Login()
    {
        int count = 3;

        bool LoginFaild = false;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                count--;
                cout << "\nInvlaid Username/Password!"<<endl;
                cout << "you Have " << count << "trails" << endl;
                
            }

            if (count == 0)
            {
                cout << "the System is Locked Please Try Again Later " << endl;
                return false;

            }


            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::find(Username, Password);
            
            LoginFaild = CurrentUser.isEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        cout << "\t\t\t\t=================================================" << endl;
        cout << "\t\t\t\t\t\t   Login Screen              " << endl;
        cout << "\t\t\t\t=================================================" << endl;
        _DrawDateAndUserName();
        cout << endl;

       return _Login();

    }

};

