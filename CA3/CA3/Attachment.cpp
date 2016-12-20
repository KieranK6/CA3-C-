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