#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	public :

	Contact();
	~Contact();

	static int objectCount;
	static int maximumCount;

	bool isUsed(void);
	void init(void);
	void show(void);
	int  getObjectCount(void);
	void showBasicInfo(int index);
	void printHeader(void);
	void showFullInfo(void);
	void showTruncate(std::string str);

	bool used;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string login;
	std::string address;
	std::string email;
	std::string phone;
	std::string birthday;
	std::string meal;
	std::string underwear;
	std::string secret;
};

#endif