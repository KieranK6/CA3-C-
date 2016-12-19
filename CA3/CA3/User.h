/**
*	Version: 1.0
*	Author: Kieran
*	Description: User class, has an email, password and username
**/

#pragma once
#include <iostream>
class User
{
public:
	User();
	User(std::string Email, std::string Password, std::string Username);
	~User();

private:
	int id;
	std::string Email, Password, Username;

protected:
	static int count;
};

