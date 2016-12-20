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

	void setFileName(std::string newFileName) { FileName = newFileName; }
	std::string getFileNameh() { return FileName; }

	void setFilePath(std::string newFilePath) { FilePath = newFilePath; }
	std::string getFilePath() { return FilePath; }

	void setFileData(char newFileData) { FileData = newFileData; }
	char getFileData() { return FileData; }

	

private:
	std::string FileName, FilePath;
	char FileData;
};

