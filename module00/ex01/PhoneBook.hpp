#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "iostream"
#include "iomanip"

class PhoneBook
{
private:
	Contact contacts[8];
	int last_contact_idx;
	int nb_contacts;

public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(PhoneBook &pb);
	PhoneBook &operator=(PhoneBook &pb);

	int getNbContacts();
	void addContact(Contact &c);
	void printContacts() const;
	void printContactDetail(int idx) const;
};

#endif
