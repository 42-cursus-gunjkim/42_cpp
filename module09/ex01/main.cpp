#include <iostream>
#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Please hand over only one file name as a parameter for the program" << std::endl;
		return 0;
	}

	Pair<int, int> ret = RPN::Calculate(argv[1]);
	int err_code = ret.Second();
	int result = ret.First();

	if (err_code == 1)
		std::cout << "Error" << std::endl;
	else
		std::cout << result << std::endl;
}