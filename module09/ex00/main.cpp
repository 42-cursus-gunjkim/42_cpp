#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2 && argc != 3)
	{
		std::cout << "Please hand over only one file name as a parameter for the program" << std::endl;
		return 0;
	}

	if (argc == 2)
	{
		try
		{
			BitcoinExchange exchanger(argv[1]);
			exchanger.Exchange();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else if (argc == 3)
	{
		try
		{
			BitcoinExchange exchanger(argv[1], argv[2]);
			exchanger.Exchange();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}
