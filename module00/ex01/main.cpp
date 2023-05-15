#include "PhoneBook.hpp"

int main()
{
	std::string command;
	PhoneBook pb;

	while (1)
	{
		std::cout << "Enter command: ";
		std::cin >> command;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickName;

			std::cout << "Enter first name: ";
			std::cin >> firstName;
			std::cout << "Enter last name: ";
			std::cin >> lastName;
			std::cout << "Enter nickname: ";
			std::cin >> nickName;
			pb.addContact(firstName, lastName, nickName);
		}
		else if (command == "SEARCH")
			pb.searchContact();
		else
			std::cout << "Invalid command" << std::endl;
	}
}