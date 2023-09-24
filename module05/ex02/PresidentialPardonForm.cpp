#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form(target, min_required_grade_to_sign, min_required_grade_to_exec)
	{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
	: Form(p.getName(), p.getSignable(), p.getExecutable())
	{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p)
{
	if (this == &p)
		return (*this);
	dynamic_cast<Form&>(*this) = p;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecutable())
		throw GradeTooLowException("Form::GradeTooLowException : Too low to exec!");
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
