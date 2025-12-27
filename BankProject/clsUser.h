#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsBank.h"
#include <vector>
#include"clsDate.h"
#include <fstream>

using namespace std;

class clsUser : public clsPerson
{
private:

    enum EnMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
    EnMode _mode;
    string _userName;
    string _password;
    int _permissions;

    bool _markedForDelete = false;
    struct stLoginRegisterRecord;


    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string line, string seperator = "#//#")
    {
        stLoginRegisterRecord loginRegisterRecord;


        vector <string> loginRegisterDataLine = clsString::Split(line, seperator);
        loginRegisterRecord.dateTime = loginRegisterDataLine[0];
        loginRegisterRecord.userName = loginRegisterDataLine[1];
        loginRegisterRecord.password = clsUtil::DecryptText(loginRegisterDataLine[2]);
        loginRegisterRecord.permissions = stoi(loginRegisterDataLine[3]);

        return loginRegisterRecord;

    }

    static clsUser _convertLineToUserObject(string line, string separator = "#//#")
    {
        vector<string> userData;
        userData = clsString::Split(line, separator);

        return clsUser(EnMode::updateMode, userData[0], userData[1], userData[2],
            userData[3], userData[4], clsUtil::DecryptText(userData[5]), stoi(userData[6]));
    }

    static string _convertUserObjectToLine(clsUser user, string separator = "#//#")
    {
        string userRecord = "";
        userRecord += user.firstName + separator;
        userRecord += user.lastName + separator;
        userRecord += user.email + separator;
        userRecord += user.phone + separator;
        userRecord += user.userName + separator;
        userRecord += clsUtil::DecryptText(user.password) + separator;
        userRecord += to_string(user.permissions);

        return userRecord;
    }

    static string _convertUserLoginObjectToLine(clsUser user, string separator = "#//#")
    {
        string userRecord = "";
       
       
        userRecord += clsDate::GetSystemDateTimeString() + separator;
        userRecord += user.userName + separator;
        userRecord += clsUtil::EncryptText(user.password) + separator;
        userRecord += to_string(user.permissions);

        return userRecord;
    }


    

    static vector <clsUser> _loadUsersDataFromFile()
    {
        vector <clsUser> users;

        fstream myFile;
        myFile.open("Users.txt", ios::in); // read Mode

        if (myFile.is_open())
        {
            string line;

            while (getline(myFile, line))
            {
                clsUser user = _convertLineToUserObject(line);
                users.push_back(user);
            }

            myFile.close();
        }

        return users;
    }

    


    static void _saveUsersDataToFile(vector <clsUser> users)
    {
        fstream myFile;
        myFile.open("UsersLogin.txt", ios::out); // overwrite

        string dataLine;

        if (myFile.is_open())
        {
            for (clsUser u : users)
            {
                
                    // we only write records that are not marked for delete.
                    dataLine = _convertUserObjectToLine(u);
                    myFile << dataLine << endl;
               
            }
            myFile.close();
        }
    }


    void _update()
    {
        vector <clsUser> users;
        users = _loadUsersDataFromFile();

        for (clsUser& u : users)
        {
            if (u.userName == userName)
            {
                u = *this;
                break;
            }
        }

        _saveUsersDataToFile(users);
    }

    



    void _addNew()
    {
        _addDataLineToFile(_convertUserObjectToLine(*this));
    }

    void _addDataLineToFile(string dataLine)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << dataLine << endl;
            myFile.close();
        }
    }
    void _addDataLineToFileUser(string dataLine)
    {
        fstream myFile;
        myFile.open("UsersLogin.txt", ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << dataLine << endl;
            myFile.close();
        }
    }

    static clsUser _getEmptyUserObject()
    {
        return clsUser(EnMode::emptyMode, "", "", "", "", "", "", 0);
    }

public: 

    enum enPermissions
    {
        pall = -1, plistClients = 1, paddNewClient = 2, pdeleteClient = 4,
        pupdateClients = 8, pfindClient = 16, ptranactions = 32, pmanageUsers = 64,
        
        puserLogin=128,pCurrencu=256

    };


    clsUser(EnMode mode, string firstName, string lastName,
        string email, string phone, string userName, string password,
        int permissions) :
        clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _userName = userName;
        _password = password;
        _permissions = permissions;
    }


    struct stLoginRegisterRecord
    {
        string dateTime;
        string userName;
        string password;
        int permissions;

    };

    bool isEmpty()
    {
        return (_mode == EnMode::emptyMode);
    }

    bool markedForDeleted()
    {
        return _markedForDelete;
    }

    string getUserName()
    {
        return _userName;
    }

    void setUserName(string userName)
    {
        _userName = userName;
    }

    __declspec(property(get = getUserName, put = setUserName)) string userName;

    void setPassword(string password)
    {
        _password = password;
    }

    string getPassword()
    {
        return _password;
    }
    __declspec(property(get = getPassword, put = setPassword)) string password;

    void setPermissions(int permissions)
    {
        _permissions = permissions;
    }

    int getPermissions()
    {
        return _permissions;
    }
    __declspec(property(get = getPermissions, put = setPermissions)) int permissions;

    static clsUser find(string userName)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::in); // read Mode

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsUser user = _convertLineToUserObject(line);
                if (user.userName == userName)
                {
                    myFile.close();
                    return user;
                }
            }
            myFile.close();
        }
        return _getEmptyUserObject();
    }

    static clsUser find(string userName, string password)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::in); // read Mode

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsUser user = _convertLineToUserObject(line);
                if (user.userName == userName && user.password == password)
                {
                    myFile.close();
                    return user;
                }
            }
            myFile.close();
        }
        return _getEmptyUserObject();
    }

    enum EnSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    EnSaveResults save()
    {
        switch (_mode)
        {
        case EnMode::emptyMode:
        {
            if (isEmpty())
            {
                return EnSaveResults::svFaildEmptyObject;
            }
        }

        case EnMode::updateMode:
        {
            _update();
            return EnSaveResults::svSucceeded;
            break;
        }

        case EnMode::addNewMode:
        {
            if (clsUser::isUserExist(_userName))
            {
                return EnSaveResults::svFaildUserExists;
            }
            else
            {
                _addNew();
               
                _mode = EnMode::updateMode;
                return EnSaveResults::svSucceeded;
            }
            break;
        }
        }
    }

    static bool isUserExist(string userName)
    {
        clsUser user = clsUser::find(userName);
        return (!user.isEmpty());
    }

    bool deleteUser()
    {
        vector <clsUser> users;
        users = _loadUsersDataFromFile();

        for (clsUser& u : users)
        {
            if (u.userName == _userName)
            {
                u._markedForDelete = true;
                break;
            }
        }

        _saveUsersDataToFile(users);

        *this = _getEmptyUserObject();

        return true;
    }

    static clsUser getAddNewUserObject(string userName)
    {
        return clsUser(EnMode::addNewMode, "", "", "", "", userName, "", 0);
    }


    static vector <clsUser> getUsersList()
    {
        return _loadUsersDataFromFile();
    }


    
    


    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->permissions == enPermissions::pall)
            return true;

        if ((Permission & this->permissions) == Permission)
            return true;
        else
            return false;

    }

    void RegisterLogIn()
    {
        _addDataLineToFileUser(_convertUserLoginObjectToLine(*this));
    }

    static  vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream myFile;
        myFile.open("UsersLogin.txt", ios::in);//read Mode

        if (myFile.is_open())
        {

            string line;

            stLoginRegisterRecord loginRegisterRecord;

            while (getline(myFile, line))
            {

                loginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);

                vLoginRegisterRecord.push_back(loginRegisterRecord);

            }

            myFile.close();

        }

        return vLoginRegisterRecord;

    }

   

};