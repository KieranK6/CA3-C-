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
int showloginmenu();
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
	std::array<std::string, 6> mainmenuitems = { "Create Email", "Send Email", "View Emails", "Search By", "Delete All", "Exit" };
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
			menuchoice = showloginmenu();

		else if (isloggedin == true)
			showmainmenu();	
		
	}while (menuchoice != -1);
	std::cout << "Exiting run menu..." << std::endl;
	
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

	sys.CreateMail();

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

int showloginmenu()
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
		//dologin
		if (sys.Login())
			isloggedin = true;

		runmenu();
	}
	else if (menuchoice == 2)
	{
		std::cout << "Registering.." << std::endl;
		//doregister
		sys.Register();
		runmenu();
	}
	else if (menuchoice == 3)
	{
		std::cout << "Resetting.." << std::endl;
		//doreset
		//sys.Reset();    --Write Reset Function in System class
		runmenu();
	}
	else if (menuchoice == 4)
	{
		std::cout << "Exitting.." << std::endl;
		
	}
	return -1;
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
		sys.CreateMail();
		runmenu();
	}
	else if (menuchoice == 2)
	{
		//send email
		std::cout << "Sending email..." << std::endl;
		sys.SendMail();
		runmenu();
	}
	else if (menuchoice == 3)
	{
		//view email
		std::cout << "Printing emails..." << std::endl;
		sys.printUserEmails();
		runmenu();
	}
	else if (menuchoice == 4)
	{
		//Search by
		std::cout << "Printing DB..." << std::endl;
		sys.printDB();
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
		sys.Logout();
		isloggedin = false;
		runmenu();
	}

}