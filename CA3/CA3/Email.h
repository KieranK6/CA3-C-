/**
*	Version: 1.0
*	Author: Kieran
*	Description: Email class, can attach data as attachment
**/

#pragma once
#include <iostream>
#include <string>
#include "Attachment.h"
#include <ctime>

class Email
{
public:
	Email();
	Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body, Attachment attachment);
	Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body);
	~Email();

	std::string sender, recipient, Subject, Body;

	bool operator==(Email rhs);

	void print();
private:
	tm Tm;
	Attachment attachment;
};

