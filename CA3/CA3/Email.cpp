#include "Email.h"

tm getCurrentTime();

Email::Email() : sender("Def_Sender"), recipient("Def_Recipient"), subject("Def _Subject"), body("Def_Body")
{
	Attachment a1;
	attachment = a1;

	Tm = getCurrentTime();

}

Email::Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body, Attachment attachment, tm time) : sender(Sender), recipient(Recipient), Subject(Subject), Body(Body),  attachment(attachment), Tm(time)
{
}

Email::Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body, Attachment attach)
	: sender(Sender), recipient(Recipient), Subject(Subject), Body(Body)
{
	Tm = getCurrentTime();
	attachment = attach;
}

Email::Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body, tm time) : sender(Sender), recipient(Recipient), Subject(Subject), Body(Body), Tm(time)
{
}

Email::Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body) : sender(Sender), recipient(Recipient), Subject(Subject), Body(Body)
{
	Tm = getCurrentTime();
}


Email::~Email()
{
}

bool Email::operator==(Email rhs)
{
	return(sender == rhs.sender && recipient == rhs.recipient && body == rhs.body);
}

bool Email::operator!=(Email rhs)
{
	return !(operator==(rhs));
}

bool Email::operator=(Email rhs)
{
	sender = rhs.getsender();
	recipient = rhs.getrecipient();
	subject = rhs.getsubject();
	body = rhs.getbody();
	attachment = rhs.attachment;
	Tm = rhs.Tm;
	return true;
}

std::ostream & operator<<(std::ostream & outstream, Email rhs)
{
	return outstream << rhs.getsender() << ", " << rhs.getrecipient() << ", " << rhs.getsubject();
}

std::istream & operator >> (std::istream & input, Email rhs)
{
	input >> rhs.sender >> rhs.recipient >> rhs.subject >> rhs.body;
	return input;
}


void Email::print()
{
	tm *time;
	time = &Tm;
	char buffer[80];
	strftime(buffer, 80, "%d/%m/%Y", time);
	if (attachment.FileName != "Def_FileName") {
		std::cout << sender + ":" + recipient + ":" + Subject + ":" + Body + ":" << buffer << ":" + attachment.FileName+attachment.FilePath + "\n";
	}
	else {
		std::cout << sender + ":" + recipient + ":" + Subject + ":" + Body + ":" << buffer << "\n";
	}
}

tm getCurrentTime()
{
	time_t now = time(0);
	tm *Tm = localtime(&now);
	return *Tm;
}


