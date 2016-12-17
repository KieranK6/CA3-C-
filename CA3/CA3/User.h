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

