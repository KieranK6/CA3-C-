#include "Attachment.h"


Attachment::Attachment() : FileName("Def_FileName"), FilePath("Def_FilePath"), FileData(1)
{
}

Attachment::Attachment(std::string FileName, std::string FilePath, char FileData)
	: FileName(FileName), FilePath(FilePath), FileData(FileData)
{
}

Attachment::Attachment(std::string FilePath) : FileName(""), FilePath(FilePath), FileData(1)
{
}

Attachment::~Attachment()
{
}

void Attachment::print()
{
	std::cout << FileName << FilePath << std::endl;
}

bool Attachment::operator==(Attachment rhs)
{
	return(FileName == rhs.FileName && FilePath == rhs.FilePath && FileData == rhs.FileData);
}

bool Attachment::operator!=(Attachment rhs)
{
	return !(operator==(rhs));
}

bool Attachment::operator=(Attachment rhs)
{
	FileName = rhs.getFileName();
	FilePath = rhs.getFilePath();
	FileData = rhs.getFileData();
	return true;
}

std::ostream & operator<<(std::ostream & outstream, Attachment rhs)
{
	return outstream << rhs.getFileName() << ", " << rhs.getFilePath() << ", " << rhs.getFileData();
}

std::istream & operator >> (std::istream & input, Attachment rhs)
{
	input >> rhs.FileName >> rhs.FilePath >> rhs.FileData;
	return input;
}
