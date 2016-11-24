#pragma once
#include <iostream>
class User
{
public:
	User();
	User(std::string Email, std::string Password, std::string UserName);
	~User();

private:
	int id;
	std::string Email, Password, UserName;

protected:
	static int count;
};

