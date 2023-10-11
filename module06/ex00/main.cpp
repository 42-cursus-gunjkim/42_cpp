#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Only one argument needed!\n";
		return 0;
	}
	ScalarConverter::convert(argv[2]);
	return 0;
}