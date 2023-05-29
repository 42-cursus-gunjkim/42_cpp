#include "PhoneBook.hpp"

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
            std::cout << "EOF reached. Exiting program." << std::endl;
            break;
        }
    	if (command == "EXIT")
        	break;
    	else if (command == "ADD")
        	pb.addContact();
    	else if (command == "SEARCH")
        	pb.searchContact();
    	else
    	{
        	std::cout << "Invalid command" << std::endl;
        	continue;
    	}
	}
}