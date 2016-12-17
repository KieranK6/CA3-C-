#include <iostream>
#include "System.h"
System sys;
int main()
{
	//cout << "Hello World" << endl;
	initialize();
	demo();
	system("pause");
	return 0;
}

void initialize() {
	sys = System();
}

void demo() {
	sys.Register();

	sys.Login();
	std::cout << sys.current;

	sys.WriteMail();

	sys.Logout();
	std::cout << sys.current;
}