#include "Intern.hpp"

Form* Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string names[3] = {"Shrubbery", "Robotomy request", "Presidential"};
	Form *f;
	
	int i;
	for (i = 0; i < 3; i++)
	{
		if (names[0].compare(name))
			break;
	}
	switch (i)
	{
		//new 실패시 예외처리도 해주어야 될듯...!
		case 0:
			f = new ShrubberyCreationForm(target);
		case 1:
			f = new RobotomyRequestForm(target);
		case 2:
			f = new PresidentialPardonForm(target);
		default:
			throw TypeDoesNotExist();
	}
}

Intern::TypeDoesNotExist::TypeDoesNotExist()
	: err_msg_("Intern::TypeDoesNotExist")
	{}

const char* Intern::TypeDoesNotExist::what() const throw()
{
	return err_msg_;
}