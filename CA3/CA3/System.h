/**
*	Version: 1.0
*	Author: Arnas
*	Description: System holds info about the users, handles login and logout etc, potentially SendMail(); and such functions
**/

#pragma once
#include "User.h"
#include "Email.h"

#include <list>

static class System {
public:
	System();
	~System();

	static User *current;
	static Database db;

	// SYSTEM FUNCTIONS
	static bool Login();
	static bool Logout();
	static bool Register();


	// POST LOGIN FUNCTIONS
	static bool IsLoggedIn();
	// below funcs call above func to make sure user is logged in
	static bool Send(Email email, User recipient);
	static bool WriteMail();
	static bool Search();

private:
};