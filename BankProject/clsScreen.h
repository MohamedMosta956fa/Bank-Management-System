#pragma once
#include <iostream>
#include "clsUser.h"
#include"clsBank.h"
#include "header.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{

    
protected:
   
    

     static void _DrawDateAndUserName()
     {

            cout << "\n\t\t\t\t\tUser: " << CurrentUser.userName << "\n";
            cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())
                << "\n\n";

     }


       
       
            

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};

