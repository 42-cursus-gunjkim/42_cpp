#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);

	for (MutantStack<int>::iterator iter = stack.begin(); iter != stack.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	for (MutantStack<int>::reverse_iterator r_iter = stack.rbegin(); r_iter != stack.rend(); r_iter++)
	{
		std::cout << *r_iter << std::endl;
	}

	MutantStack<int>::const_iterator c_iter = stack.cbegin();
	std::cout << *c_iter << std::endl;
	//*c_iter = 3;

	MutantStack<int>::const_reverse_iterator cr_iter = stack.crbegin();
	std::cout << *cr_iter << std::endl;
	// *cr_iter = 3;

	MutantStack<int> test(stack);
	for (MutantStack<int>::iterator iter = test.begin(); iter != test.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	stack = test;
	MutantStack<int> test2(stack);
	for (MutantStack<int>::iterator iter = test2.begin(); iter != test2.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
}