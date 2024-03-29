#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	typedef AForm* (Intern::*maker)(const std::string &);

	private:
		maker makers_[3];

	public:
		Intern();
		~Intern() {}
		Intern(const Intern& i);
		Intern& operator=(const Intern& i);
		AForm* makeForm(const std::string &name, const std::string &target);
		AForm* makeShrubbery(const std::string &target);
		AForm* makeRobotomy(const std::string &target);
		AForm* makePresidential(const std::string &target);
	
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