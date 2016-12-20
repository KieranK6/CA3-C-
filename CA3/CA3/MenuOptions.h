/**
*	Version: 1.0
*	Author: Kieran
*	Description: Adapted Niall's MenuOptions from java into c++
**/

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <array>
#include <algorithm>

class MenuOptions
{
public:
	MenuOptions(std::string name);
	MenuOptions();
	~MenuOptions();

	std::list<std::string> mList;

	

	void showMenu();
	bool add(std::string s);
	bool addAll(std::array<std::string, 4>, int size);
	bool contains(std::string checkstring);

	int size() { return mList.size(); }
	void clear() { mList.clear(); }

	std::string getName() { return name; }
	void setName(std::string newName) { name = newName; }

	int getIndexOfExitOption() { return indexOfExitOption; }
	void setName(int newIndex) { indexOfExitOption = newIndex; }

private:
	const std::string MenuHeaderBorder = " *************************** ";
	std::string name;
	int indexOfExitOption;
	
	
};

