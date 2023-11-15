#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	std::list<int> b;
	b.push_back(1);
	b.push_back(2);

	try
	{	
		std::cout << *(ft::easyfind(a, 4)) << std::endl;
		std::cout << *(ft::easyfind(b, -1)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}