#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> a;
	a.push_back(4);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	std::list<int> b;
	b.push_back(1);
	b.push_back(2);

	std::vector<int>::iterator ret1 = ft::easyfind(a, 1);
	if (ret1 == a.end())
		std::cout << "I can't find it!" << std::endl;
	else
		std::cout << *ret1 << std::endl;

	std::list<int>::iterator ret2 = ft::easyfind(b, 4);
	if (ret2 == b.end())
		std::cout << "I can't find it!" << std::endl;
	else
		std::cout << *ret2 << std::endl;

	return 0;
}