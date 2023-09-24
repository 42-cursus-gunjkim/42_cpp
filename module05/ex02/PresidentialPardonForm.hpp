#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		static const int min_required_grade_to_sign = 25;
		static const int min_required_grade_to_exec = 5;

	private:
		std::string target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& p);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
		virtual void execute(Bureaucrat const& executor) const;
};

#endif
