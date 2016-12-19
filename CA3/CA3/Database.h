#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Database {
public:
	Database();
	~Database();

	bool Read();
	bool Write();

private:
	const std::string path = "C:/somepath/";
	const std::string name = "db";

};