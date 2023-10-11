#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>

class ScalarConverter
{
	public:
		class ImpossibleException : public std::exception
		{
			private:
				std::string err_msg_;
			public:
				ImpossibleException();
				ImpossibleException(const char* err_msg);
				const char* what() const throw();

		};
		class NonDisplayableException : public std::exception
		{
			private:
				std::string err_msg_;
			public:
				NonDisplayableException();
				NonDisplayableException(const char* err_msg);
				const char* what() const throw();
		};
		class NanException : public std::exception
		{
			private:
				std::string err_msg_;
			public:
				NanException();
				NanException(const char* err_msg);
				const char* what() const throw();
		};

	private:
		ScalarConverter() {}
		ScalarConverter(const ScalarConverter& sc) {}
		const ScalarConverter& operator=(const ScalarConverter& sc) {}
	
	public:
		~ScalarConverter() {}
		static void convert(const std::string& literal);
};

#endif