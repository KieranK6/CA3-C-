#pragma once
#include <iostream>
#include "Attachment.h"
#include <ctime>

class Email
{
public:
	Email();
	Email(std::string Sender, std::string Recipeint, std::string Subject, std::string Body, Attachment attachment);
	~Email();
private:
	std::string Sender, Recipient, Subject, Body;
	tm Tm;
	Attachment attachment;
};

