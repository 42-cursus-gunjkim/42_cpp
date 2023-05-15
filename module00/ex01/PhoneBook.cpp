#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nbContacts(0), lastContactIdx(-1) {}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(PhoneBook &pb)
{
	nbContacts = pb.nbContacts;
	lastContactIdx = pb.lastContactIdx;
	for (int i = 0; i < 8; i++)
		contacts[i] = pb.contacts[i];
}

PhoneBook &PhoneBook::operator=(PhoneBook &pb)
{
	nbContacts = pb.nbContacts;
	lastContactIdx = pb.lastContactIdx;
	for (int i = 0; i < 8; i++)
		contacts[i] = pb.contacts[i];
	return *this;
}

void PhoneBook::addContact(std::string firstName, std::string secondName, std::string nickName)
{
	if (nbContacts < 8)
	{
		nbContacts++;
		lastContactIdx++;
		contacts[lastContactIdx].setContact(firstName, secondName, nickName);
	}
	else
		contacts[lastContactIdx].setContact(firstName, secondName, nickName);
}

void PhoneBook::searchContact()
{
	for (int i = 0; i < nbContacts; i++)
		printContact(i);

	int idx;
	std::cout << "Enter index of contact to display: ";
	std::cin >> idx;
	if (idx >= 0 && idx < nbContacts)
		printContact(idx);
	else
		std::cout << "Invalid index" << std::endl;
}

void PhoneBook::printContact(int idx)
{
	unsigned int columnWidth = 10;

	std::string firstName = contacts[idx].getFirstName();
	std::string lastName = contacts[idx].getLastName();
	std::string nickName = contacts[idx].getNickName();

	if (firstName.length() > columnWidth)
		firstName = firstName.substr(0, columnWidth - 1) + ".";
	if (lastName.length() > columnWidth)
		lastName = lastName.substr(0, columnWidth - 1) + ".";
	if (nickName.length() > columnWidth)
		nickName = nickName.substr(0, columnWidth - 1) + ".";
	std::cout << std::right << std::setw(columnWidth) << std::setfill(' ') << idx;
	std::cout << "|";
	std::cout << std::right << std::setw(columnWidth) << std::setfill(' ') << firstName;
	std::cout << "|";
	std::cout << std::right << std::setw(columnWidth) << std::setfill(' ') << lastName;
	std::cout << "|";
	std::cout << std::right << std::setw(columnWidth) << std::setfill(' ') << nickName;
	std::cout << std::endl;
}
