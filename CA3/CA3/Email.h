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

	Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body, Attachment attachment, tm time);
	Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body, Attachment attachment);

	Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body, tm time);
	Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body);
	~Email();

	void setsender(std::string newsender) { sender = newsender; }
	std::string getsender() { return sender; }

	void setrecipient(std::string newrecipient) { recipient = newrecipient; }
	std::string getrecipient() { return recipient; }

	void setsubject(std::string newsubject) { subject = newsubject; }
	std::string getsubject() { return subject; }

	void setbody(std::string newbody) { body = newbody; }
	std::string getbody() { return body; }

	std::string sender, recipient, subject, body;

	bool operator==(Email rhs);
	bool operator!=(Email rhs);
	bool operator=(Email rhs);
	friend std::ostream& operator<<(std::ostream& outstream, Email rhs);
	friend std::istream &operator >> (std::istream& input, Email rhs);
	

	void print();
	Attachment attachment;
	tm Tm;
private:
	
	
};

