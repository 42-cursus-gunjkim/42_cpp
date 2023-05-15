#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "iostream"
#include "iomanip"

class PhoneBook
{
private:
	Contact contacts[8];
	int nbContacts;
	int lastContactIdx;

public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(PhoneBook &pb);
	PhoneBook &operator=(PhoneBook &pb);
	void addContact(std::string firstName, std::string lastName, std::string nickName);
	void searchContact();
	void printContact(int idx);
};

#endif
