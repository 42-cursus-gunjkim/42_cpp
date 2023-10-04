#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		static const int min_required_grade_to_sign = 72;
		static const int min_required_grade_to_exec = 45;

	private:
		std::string target_;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& r);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& r);
		virtual void execute(Bureaucrat const& executor) const;
};

#endif