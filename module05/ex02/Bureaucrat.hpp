#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat 
{
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
				GradeTooLowException(const char* err_msg);;
				const char* what() const throw();
		};

	private:
		static const int highest_grade_ = 1;
		static const int lowest_grade_ = 150;
		const std::string name_;
		int grade_;
		Bureaucrat() {};

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const Bureaucrat &b);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void increase();
		void decrease();
		void signForm(Form& f);
		void executeForm(Form const & form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif