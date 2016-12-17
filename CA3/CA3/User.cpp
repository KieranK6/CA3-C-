#include "User.h"

int User::count = 1;

User::User() : id(count), Email("def_email"), Password("def_password"), Username("def_user" + count)
{
	count++;
}

User::User(std::string Email, std::string Password, std::string Username) : id(count), Email(Email), Password(Password), Username(Username)
{
	count++;
}

User::~User()
{
	count--;
}
