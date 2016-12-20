#include "MenuOptions.h"




MenuOptions::MenuOptions(std::string name) : name(name)
{
}

MenuOptions::MenuOptions() : name("default_menu")
{
}

MenuOptions::~MenuOptions()
{
}

void MenuOptions::showMenu()
{
	std::cout << "\n" << "***************" << name << "***************" << std::endl;

	int index = 1;
	
	for (std::string s : mList)
	{
		std::cout << "[" << index << "]" << s << std::endl;
		index++;
	}
}

bool MenuOptions::add(std::string s)
{
	if (contains(s) == false)
	{
		mList.push_back(s);
		return true;
	}
	else
		return false;
}

bool MenuOptions::addAll(std::array<std::string, 4> sArray, int size)
{
	bool success = false;
	for (int i = 0; i < size; i++)
	{
		success = add(sArray[i]);
	}
		
	return success;
}

bool MenuOptions::contains(std::string checkstring)
{
	return (std::find(mList.begin(), mList.end(), checkstring) != mList.end());

}

void MenuOptions::print()
{
	for (auto s : mList)
	{
		std::cout << s << std::endl;
	}
}
