#include "Database.h"
Database::Database()
{

}

Database::~Database()
{
}

bool Database::ReadUsers()
{
	std::string line;
	std::ifstream myfile(name+user, std::ios_base::app);
	if (myfile.is_open())
	{
		User newUser;
		std::pair<std::string, User> userPair;
		std::string username;
		std::string password;

		while (getline(myfile, line))
		{
			//std::cout << line << '\n';
			newUser = parseUser(line);
			userPair.first = newUser.username;
			userPair.second = newUser;
			userMap.insert(userPair);
			userList.push_back(newUser.username);
		}
		myfile.close();
	}
	else return false;
}

bool Database::ReadEmails() {
	std::string line;
	std::ifstream myfile(name+email, std::ios_base::app);
	if (myfile.is_open())
	{
		Email newEmail;
		std::pair<std::string, User> userPair;
		std::string username;
		std::string password;
		User *userPtr;
		Email *emailPtr;

		while (getline(myfile, line))
		{
			newEmail = parseEmail(line);
			emails.push_back(newEmail);
			emailPtr = GetEmailPointer(newEmail);

			if (Contains(newEmail.sender)) {
				userPtr = &userMap.at(newEmail.sender);
				userPtr->emails.push_back(*emailPtr);
			}
			if (Contains(newEmail.recipient)) {
				userPtr = &userMap.at(newEmail.recipient);
				userPtr->emails.push_back(*emailPtr);
			}
		}
		myfile.close();
	}
	else return false;
}

bool Database::WriteUser(std::string user, std::string password)
{
	std::ofstream myfile(name+Database::user, std::ios_base::app);
	if (!userMap.count(user)) 
	{
		if (myfile.is_open())
		{
			myfile << "\n"+user;
			myfile << ":"+password;
			myfile.close();
			userList.push_back(user);

			std::pair<std::string, User> userPair;
			userPair.first = user;
			userPair.second = User(user,password);
			userMap.insert(userPair);

			std::cout << "User created!\n";
			return true;
		}
	}
	else {
		std::cout << "Error: User already exists!\n";
	}
	return false;
}

bool Database::WriteEmail(std::string sender, std::string recipient, std::string message)
{
	std::ofstream myfile(name+email, std::ios_base::app);
		if (myfile.is_open())
		{
			myfile << sender;
			myfile << ":" + recipient;
			myfile << ":" + message + "\n";
			myfile.close();
			std::cout << "Email created!\n";

			Email newEmail = Email(sender, recipient, "subject", message);
			emails.push_back(newEmail);

			User *userPtr;
			userPtr = &userMap.at(newEmail.sender);
			userPtr->emails.push_back(*&newEmail);

			if (Contains(newEmail.recipient)) {
				userPtr = &userMap.at(newEmail.recipient);
				userPtr->emails.push_back(*&newEmail);
			}

			return true;
		}
	else return false;
}

bool Database::WriteEmail(Email e)
{
	std::ofstream myfile(name + email, std::ios_base::app);
	if (myfile.is_open())
	{
		myfile << e.sender;
		myfile << ":" + e.recipient;
		myfile << ":" + e.Body + "\n";
		myfile.close();
		std::cout << "Email created!\n";
		emails.push_back(e);

		User *userPtr;
		userPtr = &userMap.at(e.sender);
		userPtr->emails.push_back(*&e);

		if (Contains(e.recipient)) {
			userPtr = &userMap.at(e.recipient);
			userPtr->emails.push_back(*&e);
		}

		return true;
	}
	else return false;
}

bool Database::Contains(std::string username)
{
	return(std::find(userList.begin(), userList.end(), username) != userList.end());
}

User* Database::Get(std::string username)
{
	if (Contains(username)) {
		return &userMap.at(username);
	}
	return nullptr;
}

void Database::Print()
{
	std::cout << "users:\n";
	for (std::string s : userList) {
		std::cout << s << std::endl;
	}
	std::cout << "emails:\n";
	//for (Email e : emailList) {
	//	e.print();
	//}
}

User Database::parseUser(std::string line)
{
		size_t delimPos;
		size_t start = 0;
		std::string delimiter = ":";
		
		delimPos = line.find(delimiter);
		std::string username = line.substr(0, delimPos);
		std::string password = line.substr(delimPos + 1, line.length());

		return User(username, password);
}

Email Database::parseEmail(std::string line)
{
	size_t delimPos;
	size_t start = 0;
	size_t endDelimPos;
	std::string delimiter = ":";

	delimPos = line.find(delimiter);
	endDelimPos = line.find_last_of(delimiter);

	std::string sender = line.substr(0, delimPos);
	std::string recipient = line.substr(delimPos + 1, endDelimPos - delimPos-1);
	std::string message = line.substr(endDelimPos + 1, line.length());

	return Email(sender, recipient, "subject", message);
}

Email* Database::GetEmailPointer(Email e) {
	int pos = std::find(emails.begin(), emails.end(), e) - emails.begin();
	return &(emails[pos]);
}

Email& Database::GetEmailAddr(Email e) {
	int pos = std::find(emails.begin(), emails.end(), e) - emails.begin();
	return (emails[pos]);
}