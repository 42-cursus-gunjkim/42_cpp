#include <iostream>

int main()
{
	const int a = 3;
	std::cout << "Before : " << a << std::endl;
	const_cast<int&>(a) = 5;
	std::cout << "After(a) : " << a << ", 주소 : " << &a << std::endl;
	return 0;
}
