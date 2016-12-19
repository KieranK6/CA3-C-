#include "Database.h"

Database::Database()
{

}

Database::~Database()
{
}

bool Database::Read()
{
	std::string line;
	std::ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::cout << line << '\n';
		}
		myfile.close();
	}
	else return false;
}

bool Database::Write()
{
	std::ofstream myfile("example.txt");
	if (myfile.is_open())
	{
		myfile << "This is a line.\n";
		myfile << "This is another line.\n";
		myfile.close();
		return true;
	}
	else return false;
}
