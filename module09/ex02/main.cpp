#include <iostream>
#include "PmergeMe.hpp"

bool CheckInput(int argc, char** argv, std::vector<int>* outInput)
{
	if (argc < 2)
	{
		std::cout << "Please hand over a positive integer sequence as argument!" << std::endl;
		return false;
	}

	for (int i = 1; i < argc; i++)
	{
		int num = std::atoi(argv[i]);
		if (num <= 0)
		{
			std::cout << "Please hand over a positive integer sequence as argument!" << std::endl;
			return false;
		}	
		outInput->push_back(num);
	}

	return true;
}

int main(int argc, char* argv[])
{
	std::vector<int> input;
	if (CheckInput(argc, argv, &input) == false)
		return 1;

	// print input
	for (int i = 0; i < (int)input.size(); i++)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}