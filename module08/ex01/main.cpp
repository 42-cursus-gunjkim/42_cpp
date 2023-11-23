#include <iostream>
#include <ctime>
#include "Span.hpp"


int main()
{
	std::vector<int> test(5);

	test[0] = 6;
	test[1] = 3;
	test[2] = 17;
	test[3] = 9;
	test[4] = 11;
	Span sp = Span(10);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	try
	{
		sp.addRange(test.begin(), test.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << sp << std::endl;
	try
	{
		sp.addRange(5, test.begin(), test.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(10000);
	srand(time(NULL));

	for (int i = 0; i < 10000; i++)
		sp2.addNumber(rand() % 1000);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	//std::cout << sp2 << std::endl;
	return 0;
}