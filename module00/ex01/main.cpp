#include "PhoneBook.hpp"

void contactAdder(PhoneBook &pb)
{
	std::string addMsg[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	void (Contact::*setter[])(std::string &input) = {
		&Contact::setFirstName,
		&Contact::setLastName,
		&Contact::setNickName,
		&Contact::setPhoneNumber,
		&Contact::setDarkestSecret
	};
	Contact target;
	std::string temp;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter " << addMsg[i] << ": ";
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cout << "EOF detected, exiting..." << std::endl;
			return ;
		}
		if (temp.length() == 0)
		{
			std::cout << "Invalid input" << std::endl;
			i--;
			continue;
		}
		(target.*setter[i])(temp);
	}
	pb.addContact(target);
}

void contactSearcher(PhoneBook &pb)
{
	if (pb.getNbContacts() == 0)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	
	pb.printContacts();

	int index;
	std::cout << "Enter index that you want to watch : ";
	std::cin >> index;
	while (!std::cin >> index || (index < 0 && index < pb.getNbContacts()))
	{
		if (std::cin.eof())
		{
			std::cout << "EOF detected, exiting..." << std::endl;
			exit(0);
		}
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid index." << std::endl;
		std::cout << "Enter index that you want to watch : ";
		std::cin >> index;
	}
	std::cin.ignore(256, '\n');
	pb.printContactDetail(index);
}

int main()
{
	std::string command;
	PhoneBook pb;

	while (1)
	{
    	std::cout << "Enter command: ";
    	std::getline(std::cin, command);
		if (std::cin.eof())
        {
            std::cout << "EOF detected, exiting..." << std::endl;
			return 0;
        }
    	if (command == "EXIT")
        	break;
    	else if (command == "ADD")
			contactAdder(pb);
    	else if (command == "SEARCH")
        	contactSearcher(pb);
		else if (command.length() == 0)
			continue;
    	else
    	{
        	std::cout << "Invalid command" << std::endl;
        	continue;
    	}
	}
	return 0;
}