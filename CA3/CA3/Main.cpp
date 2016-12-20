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

bool isloggedin = false; //Used for menu navigating
int choice;
int menuchoice;
int takeinput();
int showloginmenu();
void showmainmenu();
void showsearchmenu();

int main()
{
	initializeMenus();
	runmenu();
	system("pause");
	return 0;
}


void initializeMenus()
{
	MenuOptions login("Log In");
	std::array<std::string, 4> loginitems = { "Log In", "Register", "Reset", "Exit" }; //fill array with menu options
	for (auto s : loginitems)
	{
		login.add(s); //Adding array into menu
	}
	menuvector.push_back(login); //Adding menu to vector of menus

	MenuOptions mainmenu("Main Menu");
	std::array<std::string, 6> mainmenuitems = { "Create Email", "Send Email", "View Emails", "Search By", "Delete All", "Exit" }; //fill array with menu options
	for (auto s : mainmenuitems)
	{
		mainmenu.add(s);
	}
	menuvector.push_back(mainmenu);

	MenuOptions searchbymenu("Search Menu");
	std::array<std::string, 4> searchbymenuitems = { "Username", "Subject", "Attachment",  "Exit" };
	for (auto s : searchbymenuitems)
	{
		searchbymenu.add(s);
	}
	menuvector.push_back(searchbymenu);
}
void runmenu()
{
	do{
		if (isloggedin == false) //If no one is logged in display login menu
			menuchoice = showloginmenu();

		else if (isloggedin == true)
			showmainmenu();	 //If someone is logged in display main menu
		
	}while (menuchoice != -1); //if exit login menu, exit app
	std::cout << "Exiting run menu..." << std::endl;
	
}


int takeinput()
{
	std::cout << "Enter your choice: ";
	std::cin >> choice; 
	return choice; //returns users int
}

int showloginmenu()
{
	MenuOptions loginmenu = menuvector[0]; //gets menu from vector
	loginmenu.showMenu(); //Displays menu options
	menuchoice = takeinput();
	
	if (menuchoice < 0 || menuchoice > loginmenu.mList.size())
	{
		std::cout << "Please enter a valid option!" << std::endl;
	}

	else if (menuchoice == 1)
	{
		//dologin
		if (sys.Login()) //if someone logs in set bool
			isloggedin = true;

		runmenu();
	}
	else if (menuchoice == 2)
	{
		std::cout << "Registering.." << std::endl;
		//doregister
		sys.Register(); //Add user to user db
		runmenu();
	}
	else if (menuchoice == 3)
	{
		std::cout << "Resetting.." << std::endl;
		//doreset
		sys.reset();   
		runmenu();
	}
	else if (menuchoice == 4)
	{
		std::cout << "Exitting.." << std::endl;
		
	}
	return -1; //to exit run menu
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
		sys.CreateMail(); //Creates emails object
		runmenu();
	}
	else if (menuchoice == 2)
	{
		//send email
		std::cout << "Sending email..." << std::endl;
		sys.SendMail(); //Sends email object
		runmenu();
	}
	else if (menuchoice == 3)
	{
		//view emails
		std::cout << "View emails..." << std::endl;
		sys.printUserEmails(); //Print Inbox, current users emails
		runmenu();
	}
	else if (menuchoice == 4)
	{
		//Search by
		showsearchmenu();
	}
	else if (menuchoice == 5)
	{
		//Delete All
		std::cout << "Delete All..." << std::endl;
		sys.deleteAll(); //clears data in email db
		runmenu();
	}
	else if (menuchoice == 6)
	{
		//Exit
		std::cout << "Exiting..." << std::endl;
		sys.Logout(); //logs current user out
		isloggedin = false; //so login menu is displayed
		runmenu();
	}

}

void showsearchmenu()
{
	MenuOptions searchmenu = menuvector[2];
	searchmenu.showMenu();
	menuchoice = takeinput();

	if (menuchoice < 0 || menuchoice > searchmenu.mList.size())
	{
		std::cout << "Please enter a valid option!" << std::endl;
	}

	else if (menuchoice == 1)
	{
		//Array of functions   Date filter
		std::cout << "Username Filter!" << std::endl;
		sys.UsernameFilter();
		showsearchmenu();
	}

	else if (menuchoice == 2)
	{
		//Array of functions   Subject filter
		std::cout << "Subject Filter!" << std::endl;
		sys.SubjectFilter();
		showsearchmenu();
	}

	else if (menuchoice == 3)
	{
		//Array of functions   username filter
		std::cout << "Attachment Filter!" << std::endl;
		sys.AttachmentFilter();
		showsearchmenu();
	}

	else if (menuchoice == 4)
	{
		//Exit
		std::cout << "Exiting..." << std::endl;
		runmenu();
	}
}