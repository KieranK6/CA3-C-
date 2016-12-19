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

	std::string username;
	std::list<Email> emails;
private:
	int id;
	std::string password;
	

protected:
	static int count;
};

