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

void User::print()
{
	std::cout << id << username << std::endl;
}

bool User::operator==(User rhs)
{
	return(username == rhs.getusername() && password == rhs.getpassword());
}

bool User::operator!=(User rhs)
{
	return !(operator==(rhs));
}

bool User::operator=(User rhs)
{
	username = rhs.getusername();
	password = rhs.getpassword();
	return true;
}

std::ostream & operator<<(std::ostream & outstream, User rhs)
{
	return outstream << rhs.getusername();
}

std::istream & operator >> (std::istream & input, User rhs)
{
	input >> rhs.username >> rhs.password;
	return input;
}
