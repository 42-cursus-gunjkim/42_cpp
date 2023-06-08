#include "MyString.hpp"

int main()
{
	MyString str1("abcde");
  MyString str2("abcde");

  std::cout << "str1 and str2 compare : " << str1.compare("abcde") << std::endl;
}
