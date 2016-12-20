/**
*	Version: 1.0
*	Author: Kieran
*	Description: To send data with an email
**/

#pragma once
#include <iostream>
#include <string>

class Attachment
{
public:
	Attachment();
	Attachment(std::string FileName, std::string FilePath, char FileData);
	~Attachment();

	void setFileName(std::string newFileName) { FileName = newFileName; }
	std::string getFileName() { return FileName; }

	void setFilePath(std::string newFilePath) { FilePath = newFilePath; }
	std::string getFilePath() { return FilePath; }

	void setFileData(char newFileData) { FileData = newFileData; }
	char getFileData() { return FileData; }

	bool operator==(Attachment rhs);
	bool operator!=(Attachment rhs);
	bool operator=(Attachment rhs);
	friend std::ostream& operator<<(std::ostream& outstream, Attachment rhs);
	friend std::istream &operator >> (std::istream& input, Attachment rhs);

	void print();

private:
	std::string FileName, FilePath;
	char FileData;
};

