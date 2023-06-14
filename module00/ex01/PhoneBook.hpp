#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "iostream"
#include "iomanip"

class PhoneBook
{
private:
	Contact contacts[8];
	int lastContactIdx;
	int nbContacts;

public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(PhoneBook &pb);
	PhoneBook &operator=(PhoneBook &pb);
	int getNbContacts() const;
	void addContact(Contact &c);
	void printContacts() const;
	void printContactDetail(int idx) const;
};

#endif
