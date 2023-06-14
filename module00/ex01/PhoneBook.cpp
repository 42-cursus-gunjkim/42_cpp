#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : lastContactIdx(-1), nbContacts(0) {}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(PhoneBook &pb)
{
	lastContactIdx = pb.lastContactIdx;
	for (int i = 0; i < 8; i++)
		contacts[i] = pb.contacts[i];
}

PhoneBook &PhoneBook::operator=(PhoneBook &pb)
{
	lastContactIdx = pb.lastContactIdx;
	for (int i = 0; i < 8; i++)
		contacts[i] = pb.contacts[i];
	return *this;
}

void PhoneBook::addContact(Contact &c)
{
	int	targetIdx = (lastContactIdx + 1) % 8;
	lastContactIdx = targetIdx;
	
	contacts[lastContactIdx] = c;
	if (nbContacts < 8)
		nbContacts++;
}

std::string fitFormat(std::string str)
{
	if (str.length() > 10)
	{
		str[9] = '.';
		str.erase(10);
	}
	return str;
}

void PhoneBook::printContacts() const {
    int columnWidth = 10;
    std::string target;

	std::cout << std::right << std::setfill(' ');
	for (int idx = 0; idx < nbContacts; idx++)
	{
		std::cout << std::setw(columnWidth) << idx << '|';
    	std::cout << std::setw(columnWidth) << fitFormat(contacts[idx].getFirstName()) << '|';
    	std::cout << std::setw(columnWidth) << fitFormat(contacts[idx].getLastName()) << '|';
    	std::cout << std::setw(columnWidth) << fitFormat(contacts[idx].getNickName()) << std::endl;
	}
}

void PhoneBook::printContactDetail(int idx) const {
	if (idx < 0 || idx >= nbContacts)
		return;
	std::cout << "First Name : " << contacts[idx].getFirstName() << std::endl;
    std::cout << "Last Name : " << contacts[idx].getLastName() << std::endl;
    std::cout << "Nick Name : " << contacts[idx].getNickName() << std::endl;
    std::cout << "Phone Number : " << contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << contacts[idx].getDarkestSecret() << std::endl;
}

int PhoneBook::getNbContacts() const { return nbContacts; }
