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

	void print();

	std::string username;
	std::list<Email> emails;
	Email* currentEmail;

	bool operator==(User rhs);
	bool operator!=(User rhs);
	bool operator=(User rhs);
	friend std::ostream& operator<<(std::ostream& outstream, User rhs);
	friend std::istream &operator >> (std::istream& input, User rhs);

private:
	int id;
	std::string password;
	

protected:
	static int count;
};

