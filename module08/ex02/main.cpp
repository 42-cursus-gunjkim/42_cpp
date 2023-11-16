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
}