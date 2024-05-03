#include <iostream>
#include <cstdlib>
#include "PmergeMe.hpp"

bool IsAllDigit(char* str)
{
	int index = 0;
	while(str[index] != '\0')
	{
		if (isdigit(str[index]) == false)
			return false;
		index++;
	}

	return true;
}

bool CheckInput(int argc, char** argv, std::vector<int>* outInput)
{
	if (argc < 2)
		return false;

	for (int i = 1; i < argc; i++)
	{
		if (IsAllDigit(argv[i]) == false)
			return false;
		int num = std::atoi(argv[i]);
		if (num <= 0)
			return false;
		outInput->push_back(num);
	}

	return true;
}

int main(int argc, char* argv[])
{
	std::vector<int> input;
	if (CheckInput(argc, argv, &input) == false)
	{
		std::cout << "Please hand over a positive integer sequence as argument!" << std::endl;
		return 1;
	}

	// print unsorted input
	for (int i = 0; i < (int)input.size(); i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;

	// sort here
	PmergeMe::Merge(input);

	// print sorted input
	for (int i = 0; i < (int)input.size(); i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;

	return 0;
}