#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : last_contact_idx(-1), nb_contacts(0) {}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(PhoneBook &pb)
{
	last_contact_idx = pb.last_contact_idx;
	for (int i = 0; i < 8; i++)
		contacts[i] = pb.contacts[i];
}

PhoneBook &PhoneBook::operator=(PhoneBook &pb)
{
	last_contact_idx = pb.last_contact_idx;
	for (int i = 0; i < 8; i++)
		contacts[i] = pb.contacts[i];
	return *this;
}

void PhoneBook::addContact(Contact &c)
{
	int	targetIdx = (last_contact_idx + 1) % 8;
	last_contact_idx = targetIdx;
	
	contacts[last_contact_idx] = c;
	if (nb_contacts < 8)
		nb_contacts++;
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

int PhoneBook::getNbContacts() {
	return this->nb_contacts;
}

void PhoneBook::printContacts() const {
    int columnWidth = 10;
    std::string target;

	std::cout << std::right << std::setfill(' ');
	
	std::cout
		<< std::setw(columnWidth) << "index" << '|'
		<< std::setw(columnWidth) << "first name" << '|'
    	<< std::setw(columnWidth) << "last name" << '|'
    	<< std::setw(columnWidth) << "nick name" << std::endl;

	for (int idx = 0; idx < nb_contacts; idx++)
	{
		std::cout 
			<< std::setw(columnWidth) << idx << '|'
    		<< std::setw(columnWidth) << fitFormat(contacts[idx].getFirstName()) << '|'
    		<< std::setw(columnWidth) << fitFormat(contacts[idx].getLastName()) << '|'
    		<< std::setw(columnWidth) << fitFormat(contacts[idx].getNickName()) << std::endl;
	}
}

void PhoneBook::printContactDetail(int idx) const {
	if (idx < 0 || idx >= nb_contacts)
	{
		std::cout << "PhoneBook : No Contact Idx [ " << idx << " ]" << std::endl;
		return;
	}
	std::cout << "First Name : " << contacts[idx].getFirstName() << std::endl;
    std::cout << "Last Name : " << contacts[idx].getLastName() << std::endl;
    std::cout << "Nick Name : " << contacts[idx].getNickName() << std::endl;
    std::cout << "Phone Number : " << contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << contacts[idx].getDarkestSecret() << std::endl;
}
