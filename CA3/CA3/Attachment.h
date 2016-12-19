/**
*	Version: 1.0
*	Author: Kieran
*	Description: To send data with an email
**/

#pragma once
#include <iostream>

class Attachment
{
public:
	Attachment();
	Attachment(std::string FileName, std::string FilePath, char FileData);
	~Attachment();

private:
	std::string FileName, FilePath;
	char FileData;
};

