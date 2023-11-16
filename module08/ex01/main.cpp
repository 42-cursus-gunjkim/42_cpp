#include "Span.hpp"
#include <iostream>

int main()
{
	std::vector<int> test(5);

	test[0] = 6;
	test[1] = 3;
	test[2] = 17;
	test[3] = 9;
	test[4] = 11;
	Span sp = Span(6);
	sp.addNumber(1);
	sp.addRange(test.begin(), test.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp << std::endl;
	return 0;
}