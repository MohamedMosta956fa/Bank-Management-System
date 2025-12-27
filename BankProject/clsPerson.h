#pragma once
#include <iostream>
#include "string.h"
using namespace std;

class clsPerson
{

private:

	string _firstName;
	string _lastName;
	string _email;
	string _phone;

public:
	clsPerson(string firstName, string lastName, string email, string phone)
	{
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phone = phone;
	}

	// --- دوال التعيين (Setters) ---
	void SetFirstName(string firstName)
	{
		_firstName = firstName;
	}

	void SetLastName(string lastName)
	{
		_lastName = lastName;
	}
	void SetEmail(string email)
	{
		_email = email;
	}
	void SetPhone(string phone)
	{
		_phone = phone;
	}


	string FullName()
	{
		return _firstName + " " + _lastName;
	}
	string FirstName()
	{
		return _firstName;
	}
	string LastName()
	{
		return _lastName;
	}
	string Email()
	{
		return _email;
	}
	string Phone()
	{
		return _phone;
	}
	__declspec(property(get = FirstName, put = SetFirstName)) string firstName;
	__declspec(property(get = LastName, put = SetLastName)) string lastName;
	__declspec(property(get = Email, put = SetEmail)) string email;
	__declspec(property(get = Phone, put = SetPhone)) string phone;

};