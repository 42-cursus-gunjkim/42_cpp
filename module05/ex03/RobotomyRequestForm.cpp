#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("RobotomyRequestForm", min_required_grade_to_sign, min_required_grade_to_exec)
	, target_(target)
	{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r)
	: Form(r.getName(), r.getSignable(), r.getExecutable())
	, target_(r.target_)
	{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	if (this == &r)
		return (*this);
	dynamic_cast<Form&>(*this) = r;
	this->target_ = r.target_;
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
		std::cout << this->target_ << " has failed to be robotomized" << std::endl;
	else
		std::cout << this->target_ << " has been robotomized successfully" << std::endl; 
}
