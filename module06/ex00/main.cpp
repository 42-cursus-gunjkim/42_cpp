#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Please enter one valid literal!" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
