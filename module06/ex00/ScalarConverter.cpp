#include "ScalarConverter.hpp"

void convert_to_char(const std::string& literal)
{
	int len = literal.length();

	if (len == 0 || len > 1)
		throw ScalarConverter::ImpossibleException();
	else if (len == 1 && literal[0] >= 0 && literal[0] < 32)
		throw ScalarConverter::NonDisplayableException();
	std::cout << "char: " << static_cast<char>(literal[0]) << '\n';
}

void convert_to_int(const std::string& literal);
void convert_to_float(const std::string& literal);
void convert_to_double(const std::string& literal);

void ScalarConverter::convert(const std::string& literal)
{
	try
	{
		convert_to_char(literal);
	}
	catch(const std::exception& e)
	{
		std::cout << "char: " << e.what() << '\n';
	}

	try
	{
		convert_to_int(literal);
	}
	catch(const std::exception& e)
	{
		std::cout << "int: " << e.what() << '\n';
	}
	
	try
	{
		convert_to_float(literal);
	}
	catch(const std::exception& e)
	{
		std::cout << "float: " << e.what() << '\n';
	}
	
	try
	{
		convert_to_double(literal);
	}
	catch(const std::exception& e)
	{
		std::cout << "double: " << e.what() << '\n';
	}
}

ScalarConverter::ImpossibleException::ImpossibleException() : err_msg_("impossible") {}
ScalarConverter::ImpossibleException::ImpossibleException(const char* err_msg) : err_msg_(err_msg) {}
const char* ScalarConverter::ImpossibleException::what() const throw()
{
	return this->err_msg_.c_str();
}

ScalarConverter::NanException::NanException() : err_msg_("nan") {}
ScalarConverter::NanException::NanException(const char* err_msg) : err_msg_(err_msg) {}
const char* ScalarConverter::NanException::what() const throw()
{
	return this->err_msg_.c_str();
}

ScalarConverter::NonDisplayableException::NonDisplayableException() : err_msg_("Non displayable") {}
ScalarConverter::NonDisplayableException::NonDisplayableException(const char* err_msg) : err_msg_(err_msg) {}
const char* ScalarConverter::NonDisplayableException::what() const throw()
{
	return this->err_msg_.c_str();
}