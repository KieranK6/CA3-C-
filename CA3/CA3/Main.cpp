#include <iostream>
#include "System.h"

System sys;
void demo();
void initialize();

int main()
{
	//cout << "Hello World" << endl;
	initialize();
	demo();
	system("pause");
	return 0;
}

void initialize() {
	//sys = System();
}
void demo() {
	//System::Register();
	//System::current;
	sys.printDB();
	
	sys.Register(); // Registers a new user

	sys.printDB();	// Prints the list of users

	sys.Login();	// nothing atm

	sys.printUserEmails();

	if (sys.IsLoggedIn()) {
		// someone is logged in
		std::cout << "Hello "+sys.current->username+"!\n"; // example
	}
	else {
		// nobodys logged in
	}

	sys.WriteMail();

	sys.Logout();
}