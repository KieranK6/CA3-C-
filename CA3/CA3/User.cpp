#include "User.h"

int User::count = 1;

User::User() : id(count), Email("def_email"), Password("def_password"), UserName("def_user" + count)
{
	count++;
}

User::User(std::string Email, std::string Password, std::string UserName) 
	: id(count), Email(Email), Password(Password), UserName(UserName)
{
	count++;
}

User::~User()
{
	count--;
}
