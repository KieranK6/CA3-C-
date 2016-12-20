/**
*	Version: 1.0
*	Author: Arnas
*	Description: System holds info about the users, handles login and logout etc, potentially SendMail(); and such functions
**/

#pragma once
#include "User.h"
#include "Email.h"
#include "Database.h"

#include <list>

static class System {
public:
	System();
	~System();

	User *current;
	Database db;

	// SYSTEM FUNCTIONS
	void InitializeDB();
	bool Login();
	bool Logout();
	bool Register();


	// POST LOGIN FUNCTIONS
	bool IsLoggedIn();
	// below funcs call above func to make sure user is logged in
	bool CreateMail();
	bool SendMail();
	bool Search();

	bool SubjectFilter();
	bool DateFilter();
	bool UsernameFilter();
	bool deleteAll();
	bool reset();
	// DEBUG FUNCTIONS
	void printDB();
	void printUserEmails();
private:
};