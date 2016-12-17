#include "System.h"

System::System()
{
}

System::~System()
{
}

bool System::Login()
{
	// check if such user exists, maybe hashmap for storing usernames?? else false
	// currentuser = thisuser

	return false;
}

bool System::Logout()
{
	// if somebody is logged in
	// currentuser = nullptr; return true
	// else false

	return false;
}

bool System::Register()
{
	// check if user exists else false
	// create user and add to the database
	// return Login();

	return false;
}

bool System::IsLoggedIn()
{
	if (current == nullptr) {
		return false;
	}
	return true;
}
