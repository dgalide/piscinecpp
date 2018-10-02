#include "Contact.hpp"
#include <string>
#include <iostream>

void addContact(Contact list[8]) {

	if (list[0].getObjectCount() == list[0].getMaximumCount()) {
		std::cout << "Maximum Number Of Contact Reached" << std::endl;
	} else {
		for (int i = 0; i < list[0].getMaximumCount(); i++) {
			if (list[i].isUsed() == false) {
				list[i].init();
				break;
			}
		}
	}
}

bool search(Contact list[8]) {

	int leastOne = false;

	for (int i = 0; i < list[0].getMaximumCount(); i++) {
		if (list[i].isUsed()) {
			leastOne = true;
		}
	}

	if (leastOne == true) {
		list[0].printHeader();
	}

	for (int i = 0; i < list[0].getMaximumCount(); i++) {
		if (list[i].isUsed()) {
			list[i].showBasicInfo(i);
		}
	}

	return leastOne;
}

void show(Contact list[8], int index) {

	if (index < 0 || index > 7) {
		std::cout << "Index Not Valid" << std::endl;
	} else {
		if (!(list[index].isUsed())) {
			std::cout << "Index Not Valid" << std::endl;
		} else {
			list[index].showFullInfo();
		}
	}
}

bool isInteger(std::string str) {
    if (str.empty())
        return false;

    if (str.length() > 1) {
    	return false;
    }

    if (!std::isdigit(str[0])) {
    	return false;
    }
    return true;
}

int main (void) {

	Contact			list[8];
	std::string		command;
	std::string		index;

	while (command != "EXIT")
	{
		std::cout << "Enter a command -> Allowed command : ADD, SEARCH, EXIT" << std::endl;
		std::getline (std::cin, command);
		if (std::cin.eof()==1) {
			break;
		}
		if (command == "ADD") {
			addContact(list);
		} else if (command == "EXIT") {
			break;
		} else if (command == "SEARCH") {
			if (search(list)) {
				std::cout << "Enter the wanted index" << std::endl;
				std::getline (std::cin, index);
				if (std::cin.eof()==1) {
					break;
				}
				if (isInteger(index)) {
					int i_index = std::stoi(index);
					show(list, i_index);
				} else {
					std::cout << "Only Non-Signed Digit Accepted Such as [0,1,2,3,4,5,6,7]" << std::endl;
				}
			}
		} else {
			std::cout << "Only the following commands are allowed : ADD, SEARCH, EXIT" << std::endl;
		}
	}
}