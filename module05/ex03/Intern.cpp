#include "Intern.hpp"

Intern::Intern()
{
	this->makers_[0] = &Intern::makeShrubbery;
	this->makers_[1] = &Intern::makeRobotomy;
	this->makers_[2] = &Intern::makePresidential;
}

Intern::Intern(const Intern& i)
{
	this->makers_[0] = i.makers_[0];
	this->makers_[1] = i.makers_[1];
	this->makers_[2] = i.makers_[2];
}

Intern& Intern::operator=(const Intern& i)
{
	if (this == &i)
		return *this;
	this->makers_[0] = i.makers_[0];
	this->makers_[1] = i.makers_[1];
	this->makers_[2] = i.makers_[2];
	return *this;
}

AForm* Intern::makeShrubbery(const std::string& target)
{
	AForm* f;

	f = new ShrubberyCreationForm(target);
	return f;
}

AForm* Intern::makeRobotomy(const std::string& target)
{
	AForm* f;

	f = new RobotomyRequestForm(target);
	return f;
}

AForm* Intern::makePresidential(const std::string& target)
{
	AForm* f;

	f = new PresidentialPardonForm(target);
	return f;
}

AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string names[3] = {"shrubbery create", "robotomy request", "presidential pardon"};
	AForm *f;

	int i;
	for (i = 0; i < 3; i++)
	{
		if (names[i] == name)
			break;
	}
	if (i == 3)
		throw TypeDoesNotExist();
	f = (this->*makers_[i])(target);
	std::cout << "Intern creates " << f->getName() << std::endl;
	return f;
}

Intern::TypeDoesNotExist::TypeDoesNotExist()
	: err_msg_("Intern::TypeDoesNotExist")
	{}

const char* Intern::TypeDoesNotExist::what() const throw()
{
	return err_msg_;
}