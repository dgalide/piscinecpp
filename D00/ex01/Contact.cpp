#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <regex>

// Static class members
int Contact::objectCount = 0;
int Contact::maximumCount = 8;

// Constructor
Contact::Contact(void): used(false) { }

// Destructor
Contact::~Contact(void) {}

bool 	Contact::isUsed(void) {
	return used;
}

int 	Contact::getObjectCount(void) {
	return objectCount;
}

int 	Contact::getMaximumCount(void) {
	return maximumCount;
}

void	Contact::printHeader(void) {
	showTruncate("index");
	std::cout << "|";
	showTruncate("First Name");
	std::cout << "|";
	showTruncate("Last Name");
	std::cout << "|";
	showTruncate("Nickname");
	std::cout << std::endl;
}

void 	Contact::showBasicInfo(int index) {
	std::string s_index = std::to_string(index);
	showTruncate(s_index);
	std::cout << "|";
	showTruncate(firstName);
	std::cout << "|";
	showTruncate(lastName);
	std::cout << "|";
	showTruncate(nickName);
	std::cout << std::endl;
}

void	Contact::init(void) {
	std::cout << objectCount << std::endl;
	std::cout << "Enter A First Name " << std::endl;
	std::getline (std::cin, firstName);
	std::cout << "Enter A Last Name " << std::endl;
	std::getline (std::cin, lastName);
	std::cout << "Enter A Nick Name " << std::endl;
	std::getline (std::cin, nickName);
	std::cout << "Enter A Login" << std::endl;
	std::getline (std::cin, login);
	std::cout << "Enter A Postal Address" << std::endl;
	std::getline (std::cin, address);
	std::cout << "Enter A Email" << std::endl;
	std::getline (std::cin, email);
	std::cout << "Enter A Phone Number" << std::endl;
	std::getline (std::cin, phone);
	std::cout << "Enter A Birthday" << std::endl;
	std::getline (std::cin, birthday);
	std::cout << "Enter A Favorite Meal" << std::endl;
	std::getline (std::cin, meal);
	std::cout << "Enter A Underwear Color" << std::endl;
	std::getline (std::cin, underwear);
	std::cout << "Enter A Darkest Secret" << std::endl;
	std::getline (std::cin, secret);
	objectCount++;
	used = true;
}

void	Contact::showTruncate(std::string str)
{
	char	buffer[11];

	std::cout << std::setfill (' ') << std::setw (10);
	if (str.size() > 10)
	{
		str.copy(buffer, 9, 0);
		buffer[9]='.';
		buffer[10]='\0';
		std::cout << buffer;
	}
	else
		std::cout << str;
}

void	Contact::showFullInfo(void) {
	std::cout << "Firstname: " << firstName << std::endl;
	std::cout << "Lastname: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Login: " << login << std::endl;
	std::cout << "Postal Address: " << address << std::endl;
	std::cout << "Email: " << email << std::endl;
	std::cout << "Phone Number: " << phone << std::endl;
	std::cout << "Birthday: " << birthday << std::endl;
	std::cout << "Favorite Meal: " << meal << std::endl;
	std::cout << "Underwear Color: " << underwear << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;	
}

