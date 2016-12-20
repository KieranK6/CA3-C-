#include "Email.h"

tm getCurrentTime();

Email::Email() : sender("Def_Sender"), recipient("Def_Recipient"), subject("Def _Subject"), body("Def_Body")
{
	Attachment a1;
	attachment = a1;

	Tm = getCurrentTime();

}

Email::Email(std::string Sender, std::string Recipeint, std::string Subject, std::string Body, Attachment attach)
	: sender(Sender), recipient(Recipeint), subject(Subject), body(Body)
{
	Tm = getCurrentTime();
	attachment = attach;
}

Email::Email(std::string Sender, std::string Recipient, std::string Subject, std::string Body) : sender(Sender), recipient(Recipient), subject(Subject), body(Body)
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

void Email::print()
{
	std::cout << sender + ":" + recipient + ":" + body + "\n";
}

tm getCurrentTime()
{
	time_t now = time(0);
	tm *Tm = localtime(&now);
	return *Tm;
}
