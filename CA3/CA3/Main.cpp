#include <iostream>
#include "System.h"
#include "MenuOptions.h"
#include "GenericMap.h"
#include <array>
#include <vector>

System sys;
//GenericMap<std::string, MenuOptions> menuMap;
std::vector<MenuOptions> menuvector;
void demo();
void demoMenu();
void initialize();
void initializeMenus();
void runmenu();

bool isloggedin = false;
int choice;
int menuchoice;
int takeinput();
void showloginmenu();
void showmainmenu();

int main()
{
	initializeMenus();
	runmenu();
	//cout << "Hello World" << endl;
	//initialize();
	//demo();
	//demoMenu();
	system("pause");
	return 0;
}

void initialize() {
	//sys = System();
}
void initializeMenus()
{
	MenuOptions login("Log In");
	std::array<std::string, 4> loginitems = { "Log In", "Register", "Reset", "Exit" };
	for (auto s : loginitems)
	{
		login.add(s);
	}
	//menuMap.add("loginmenu", login);
	menuvector.push_back(login);

	MenuOptions mainmenu("Main Menu");
	std::array<std::string, 6> mainmenuitems = { "Create Email", "Delete Email", "View Emails", "Search By", "Delete All", "Exit" };
	for (auto s : mainmenuitems)
	{
		mainmenu.add(s);
	}
	menuvector.push_back(mainmenu);
}
void runmenu()
{
	do{
		if (isloggedin == false)
			showloginmenu();

		else if (isloggedin == true)
			showmainmenu();	
		
	}while (menuchoice != menuvector.size());
	std::cout << "Exiting..." << std::endl;
	
}
void demo() {
	//System::Register();
	//System::current;
	sys.printDB();
	
	sys.Register(); // Registers a new user

	sys.printDB();	// Prints the list of users

	sys.Login();	// nothing atm

	sys.printUserEmails();

	if (sys.IsLoggedIn()) {
		// someone is logged in
		std::cout << "Hello "+sys.current->username+"!\n"; // example
	}
	else {
		// nobodys logged in
	}

	sys.WriteMail();

	sys.Logout();
}

void demoMenu()
{
	

	/*int choice;
	bool exit = false;
	do {
		mainmenu.showMenu();

		std::cin >> choice;
		if (choice <= 0 || choice > mainmenuitems.size())
			std::cout << "Please enter a valid choice!" << std::endl;

		else if (choice == mainmenuitems.size())
		{
			std::cout << "Exit!!";
			exit = true;
		}
			
	} while (exit = false);*/

}

int takeinput()
{
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	return choice;
}

void showloginmenu()
{
	MenuOptions loginmenu = menuvector[0];
	loginmenu.showMenu();
	menuchoice = takeinput();
	
	if (menuchoice < 0 || menuchoice > loginmenu.mList.size())
	{
		std::cout << "Please enter a valid option!" << std::endl;
	}

	else if (menuchoice == 1)
	{
		isloggedin = true;
		//dologin
		runmenu();
	}
	else if (menuchoice == 2)
	{
		std::cout << "Registering.." << std::endl;
		//doregister
		runmenu();
	}
	else if (menuchoice == 3)
	{
		std::cout << "Resetting.." << std::endl;
		//doreset
		runmenu();
	}
	else if (menuchoice == 4)
	{
		std::cout << "Exitting.." << std::endl;
	}

}

void showmainmenu()
{
	MenuOptions mainmenu = menuvector[1];
	mainmenu.showMenu();
	menuchoice = takeinput();

	if (menuchoice < 0 || menuchoice > mainmenu.mList.size())
	{
		std::cout << "Please enter a valid option!" << std::endl;
	}

	else if (menuchoice == 1)
	{
		//create email
		std::cout << "Creating email..." << std::endl;
		runmenu();
	}
	else if (menuchoice == 2)
	{
		//send email
		std::cout << "Sending email..." << std::endl;
		runmenu();
	}
	else if (menuchoice == 3)
	{
		//view email
		std::cout << "Viewing emails..." << std::endl;
		runmenu();
	}
	else if (menuchoice == 4)
	{
		//Search by
		std::cout << "Search By..." << std::endl;
		runmenu();
	}
	else if (menuchoice == 5)
	{
		//Delete All
		std::cout << "Delete All..." << std::endl;
		runmenu();
	}
	else if (menuchoice == 6)
	{
		//Exit
		std::cout << "Exiting..." << std::endl;
		runmenu();
	}

}