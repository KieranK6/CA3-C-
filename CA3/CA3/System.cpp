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

bool System::CreateMail()
{
	std::string subject;
	std::string recipient;
	std::string message;
	std::string attachment;

	std::cout << "Enter recipient:\n";
	std::cin >> recipient;

	std::cout << "Enter subject:\n";
	std::cin >> subject;

	std::cout << "Enter message:\n";
	std::cin >> message;

	std::string choice;
	std::cout << "Would you like to add an attachment? y/n\n";
	std::cin >> choice;

	if (choice == "y") {
		std::string name, path;

		std::cout << "Enter attachment name:\n";
		std::cin >> name;
		std::cout << "Enter attachment path:\n";
		std::cin >> path;
		Attachment at = Attachment(name, path, 'data');
		current->currentEmail = new Email(current->username, recipient, subject, message, at);
	}
	else {
		current->currentEmail = new Email(current->username, recipient, subject, message);
	}
	return true;
}

bool System::SendMail()
{
	if (current->currentEmail == nullptr) {
		std::cout << "No email written!\n";
		return false;
	}
	if (db.WriteEmail(*(current->currentEmail))) {
		current->currentEmail = nullptr;
		std::cout << "Sent!\n";
		return true;
	}
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
