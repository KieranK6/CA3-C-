#include <iostream>
#include "System.h"
#include "MenuOptions.h"
#include <array>

System sys;
void demo();
void demoMenu();
void initialize();

int main()
{
	//cout << "Hello World" << endl;
	//initialize();
	//demo();
	demoMenu();
	system("pause");
	return 0;
}

void initialize() {
	//sys = System();
}
void demo() {
	//System::Register();
	//System::current;
	sys.Register();

	sys.Login();
	//std::cout << sys.current;

	//sys.WriteMail();

	sys.Logout();
	//std::cout << sys.current;
}

void demoMenu()
{
	MenuOptions mainmenu("mainmenu");
	std::array<std::string, 2> menu = { "test", "test" };
	std::string mainmenuitems[4] = { "LogIn", "Register", "Settings", "Exit" };
	mainmenu.addAll(mainmenuitems, 4);
	mainmenu.showMenu();
	int choice = 0;
	std::cin >> choice;

	if (choice == menu.size())
		std::cout << "Exit!!";

}