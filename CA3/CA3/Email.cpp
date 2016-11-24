#include "Email.h"


Email::Email() : Sender("Def_Sender"), Recipient("Def_Recipient"), Subject("Def _Subject"), Body("Def_Body")
{
	Attachment a1;
	attachment = a1;

	Tm = getCurrentTime();

}

Email::Email(std::string Sender, std::string Recipeint, std::string Subject, std::string Body, Attachment attach)
	: Sender(Sender), Recipient(Recipeint), Subject(Subject), Body(Body)
{
	Tm = getCurrentTime();
	attachment = attach;
}


Email::~Email()
{
}

tm getCurrentTime()
{
	time_t now = time(0);
	tm *Tm = localtime(&now);
	return *Tm;
}
