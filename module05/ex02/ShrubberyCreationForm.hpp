#pragma once
#ifndef SHRUBBERYCREATIONFROM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		static const int min_required_grade_to_sign = 145;
		static const int min_required_grade_to_exec = 137;

	private:
		std::string target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& s);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
		virtual void execute(Bureaucrat const& executor) const;
};

#endif
