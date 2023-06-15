#include <iostream>

int main()
{
	std::cout << "Enter number : ";

	int sum = 0;
	int input;

	while (std::cin >> input)
	{
		sum += input;
	}

	std::cout << "Result : " << sum << std::endl;
	std::cin >> input;
	std::cout << input << std::endl;
	return 0;
}