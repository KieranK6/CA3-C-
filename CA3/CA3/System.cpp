#include "System.h"

System::System()
{
	InitializeDB();
}

System::~System()
{
}

void System::InitializeDB()
{
	db.ReadUsers();
	db.ReadEmails();
}

bool System::Login()
{
	std::string username;
	std::string password;
	
	std::cout << "Enter username: \n";
	std::cin >> username;

	std::cout << "Enter password: \n";
	std::cin >> password;

	current = db.Get(username);
	if (current != nullptr) {
		std::cout << "Logged in as: " + username + "\n";
		return true;
	}
	std::cout << "Error logging in!\n";
	return false;
}

bool System::Logout()
{
	// if somebody is logged in
	// currentuser = nullptr; return true
	// else false
	if (current != nullptr) {
		current = nullptr;
		std::cout << "Logged out!\n";
		return true;
	}
	return false;
}

bool System::Register()
{
	std::string name, password;

	std::cout << "Enter name: \n";
	std::cin >> name;
	std::cout << "Enter password: \n";
	password = "password";
	return(db.WriteUser(name, password));

	// check if user exists else false
	// create user and add to the database
	// return Login();
}

bool System::IsLoggedIn()
{
	if (current == nullptr) {
		return false;
	}
	return true;
}

bool System::WriteMail()
{
	std::string recipient;
	std::string message;

	std::cout << "Enter recipient:\n";
	std::cin >> recipient;
	std::cout << "Enter message:\n";
	std::cin >> message;

	return (db.WriteEmail(current->username, recipient, message));
}

void System::printDB()
{
	db.Print();
}

void System::printUserEmails()
{
	for (Email e : current->emails) {
		e.print();
	}
}
