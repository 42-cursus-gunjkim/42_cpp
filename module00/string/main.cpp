#include "MyString.hpp"

int main()
{
	MyString str1("a word");
	MyString str2("sentence");
	MyString str3("sentence");

	if (str1 == str2)
		std::cout << "str1 and str2 are equal." << std::endl;
	else
		std::cout << "str1 and str2 are different." << std::endl;
	
	if (str2 == str3)
		std::cout << "str2 and str3 are equal." << std::endl;
	else
		std::cout << "str2 and str3 are different." << std::endl;
}
