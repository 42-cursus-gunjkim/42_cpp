#include "PhoneBook.hpp"
#include <sstream>
#include <cstdio>

void contactAdder(PhoneBook &pb)
{
	std::string add_msg[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
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
		std::cout << "Enter " << add_msg[i] << ": ";
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			clearerr(stdin);
			std::cin.clear();
			i--;
			std::cout << std::endl;
			continue;
		}
		if (temp.length() == 0)
		{
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
		std::cout << "PhonBook : There is no contact in PhoneBook..." << std::endl;
		return;
	}

	pb.printContacts();

	std::string index_str;
	int index = 0;

	while (1)
	{
		std::cout << "Enter index that you want to watch : ";
		std::getline(std::cin, index_str);
		if (std::cin.eof())
		{
			clearerr(stdin);
			std::cin.clear();
			continue;
		}
		std::stringstream ss(index_str);
		ss >> index;
		if (ss.fail())
		{
			std::cout << "Enter numeric Index..." << std::endl;
			continue;
		}
		else
			break;
	}
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
            clearerr(stdin);
			std::cin.clear();
			continue;
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