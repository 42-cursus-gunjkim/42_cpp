#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const static int highest_grade_ = 1;
		const static int lowest_grade_ = 150;
		const std::string name_;
		bool is_signed_;
		const int signable_;
		const int executable_;
		AForm();

	public:
		AForm(const std::string& name);
		AForm(const std::string& name, int signable, int executable);
		virtual ~AForm();
		AForm(const AForm& f);
		const AForm& operator=(const AForm& f);
		std::string getName() const;
		bool getIsSigned() const;
		int getSignable() const;
		int getExecutable() const;
		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const& executor) const = 0;

	public:
		class GradeTooHighException : public std::exception
		{
			private:
				const char* err_msg_;
			public:
				GradeTooHighException();
				GradeTooHighException(const char* err_msg);
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				const char* err_msg_;
			public:
				GradeTooLowException();
				GradeTooLowException(const char* err_msg);
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			private:
				const char* err_msg_;
			public:
				FormNotSignedException();
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif