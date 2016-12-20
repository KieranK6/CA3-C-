/**
*	Version: 1.0
*	Author: Kieran
*	Description: User class, has an email, password and username
**/

#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Email.h"

class User
{
public:
	User();
	User(std::string username, std::string password);
	~User();

	void setusername(std::string newusername) { username = newusername; }
	std::string getusername() { return username; }

	void setpassword(std::string newpassword) { password = newpassword; }
	std::string getpassword() { return password; }

	

	std::string username;
	std::list<Email> emails;
	Email* currentEmail;
private:
	int id;
	std::string password;
	

protected:
	static int count;
};

