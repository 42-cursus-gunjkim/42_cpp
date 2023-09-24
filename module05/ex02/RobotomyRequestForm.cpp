#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form(target, min_required_grade_to_sign, min_required_grade_to_exec)
	{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r)
	: Form(r.getName(), r.getSignable(), r.getExecutable())
	{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	if (this == &r)
		return (*this);
	dynamic_cast<Form&>(*this) = r;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecutable())
		throw GradeTooLowException("Form::GradeTooLowException : Too low to exec!");
	srand((unsigned int)time(NULL));
	int coin = rand() % 2;
	std::cout << "drilling sounds....." << std::endl;
	if (coin == 0)
		std::cout << this->getName() << " has failed to be robotomized" << std::endl;
	else
		std::cout << this->getName() << " has been robotomized successfully" << std::endl; 
}
