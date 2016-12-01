#pragma once
#include <iostream>
#include <list>
#include <array>

class MenuOptions
{
public:
	MenuOptions(std::string name, int indexOfExitOption);
	MenuOptions();
	~MenuOptions();

	int showMenuGetChoice(std::string strPrompt);
	bool add(std::string s);
	bool addAll(std::string sArray[]);

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
	std::list<std::string> mList;
	
};

