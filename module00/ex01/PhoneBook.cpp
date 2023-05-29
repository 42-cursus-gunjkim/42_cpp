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

void PhoneBook::addContact()
{
	int	targetIdx = (lastContactIdx + 1) % 8;
	lastContactIdx = targetIdx;
	std::string input;

	std::cout << "Enter first name : ";
	std::cin >> input;
	contacts[targetIdx].setFirstName(input);
	std::cout << "Enter second name : ";
	std::cin >> input;
	contacts[targetIdx].setLastName(input);
	std::cout << "Enter nickname : ";
	std::cin >> input;
	contacts[targetIdx].setNickName(input);
	std::cout << "Enter phone number : ";
	std::cin >> input;
	contacts[targetIdx].setPhoneNumber(input);
	std::cout << "Enter darkest secret : ";
	std::cin >> input;
	contacts[targetIdx].setDarkestSecret(input);
	std::cout << "Succefully Added!" << std::endl;
	nbContacts++;
}

void PhoneBook::searchContact()
{
    int target;

    if (nbContacts == 0)
    {
        std::cout << "There are no contacts in the phonebook." << std::endl;
        return;
    }

    for (int i = 0; i < nbContacts; i++)
        printContact(i);

    std::cout << "Enter the entry that you want to watch: ";
    while (!(std::cin >> target) || target < 0 || target >= nbContacts)
    {
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid entry. Enter the entry that you want to watch: ";
    }

    std::cout << "First Name : " << contacts[target].getFirstName() << std::endl;
    std::cout << "Last Name : " << contacts[target].getLastName() << std::endl;
    std::cout << "Nick Name : " << contacts[target].getNickName() << std::endl;
    std::cout << "Phone Number : " << contacts[target].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << contacts[target].getDarkestSecret() << std::endl;
}

std::string fitFormat(std::string str)
{
	if (str.length() > 10)
		str[9] = '.';
	return str;
}

void PhoneBook::printContact(int idx) {
    unsigned int columnWidth = 10;
    std::string target;

    std::cout << std::right << std::setw(columnWidth) << std::setfill(' ') << idx << '|';
    std::cout << std::right << std::setw(columnWidth) << std::setfill(' ') << fitFormat(contacts[idx].getFirstName()) << '|';
    std::cout << std::right << std::setw(columnWidth) << std::setfill(' ') << fitFormat(contacts[idx].getLastName()) << '|';
    std::cout << std::right << std::setw(columnWidth) << std::setfill(' ') << fitFormat(contacts[idx].getNickName()) << std::endl;
}
