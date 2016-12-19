#include "User.h"

int User::count = 1;

User::User()
{
	count++;
	currentEmail = new Email();
	currentEmail = nullptr;
}

User::User(std::string username, std::string password) : id(count), username(username), password(password)
{
	count++;
	currentEmail = new Email();
	currentEmail = nullptr;
}


User::~User()
{
	delete currentEmail;
	currentEmail = nullptr;
	count--;
}
