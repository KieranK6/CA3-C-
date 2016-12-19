#include "User.h"

int User::count = 1;

User::User()
{
}

User::User(std::string username, std::string password) : id(count), username(username), password(password)
{
	count++;
}


User::~User()
{
	count--;
}
