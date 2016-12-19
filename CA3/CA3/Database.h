#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Email.h"
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
class Database {
public:
	Database();
	~Database();

	bool ReadUsers();
	bool ReadEmails();

	bool WriteUser(std::string user, std::string password);
	bool WriteEmail(std::string user, std::string recipient, std::string message);
	bool WriteEmail(Email e);

	bool Contains(std::string username);
	User* Get(std::string username);
	void Print();
private:
	const std::string path = "C:/somepath/";
	const std::string name = "db";
	const std::string email = "-emails";
	const std::string user = "-users";
	
	std::unordered_map<std::string, User> userMap;
	std::list<std::string> userList;

	std::vector<Email> emails;

	void build();
	User parseUser(std::string line);
	Email parseEmail(std::string line);
	Email* GetEmailPointer(Email e);
	Email& GetEmailAddr(Email e);
};