#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	typedef Form* (Intern::*maker)(const std::string &);

	private:
		maker makers_[3];
	public:
		Intern();
		~Intern() {}
		Intern(const Intern& i);
		Intern& operator=(const Intern& i) {}
		Form* makeForm(const std::string &name, const std::string &target);
		Form* makeShrubbery(const std::string &target);
		Form* makeRobotomy(const std::string &target);
		Form* makePresidential(const std::string &target);
	
	public:
		class TypeDoesNotExist : public std::exception
		{
			private:
				const char* err_msg_;
			
			public:
				TypeDoesNotExist();
				const char* what() const throw();

		};
};

#endif