#include "Intern.hpp"

Intern::Intern()
{
	makers_[0] = Intern::makeShrubbery;
	makers_[1] = Intern::makeRobotomy;
	makers_[2] = Intern::makePresidential;
}

Intern::Intern(const Intern& i)
{
	makers_[0] = i.makers_[0];
	makers_[1] = i.makers_[1];
	makers_[2] = i.makers_[2];
}

Form* Intern::makeShrubbery(const std::string& target)
{
	Form* f;

	try
	{
		f = new ShrubberyCreationForm(target);
	}
	catch (std::exception& e)
	{
		throw e;
	}
}

Form* Intern::makeRobotomy(const std::string& target)
{
	Form* f;

	try
	{
		f = new RobotomyRequestForm(target);
	}
	catch (std::exception& e)
	{
		throw e;
	}
}

Form* Intern::makePresidential(const std::string& target)
{
	Form* f;

	try
	{
		f = new PresidentialPardonForm(target);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Intern creates "
}

Form* Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string names[3] = {"shrubbery create", "robotomy request", "presidential pardon"};
	Form *f;

	int i;
	for (i = 0; i < 3; i++)
	{
		if (names[0].compare(name))
			break;
	}
	if ()
	f = (this->*makers_[i])(target);
}

Intern::TypeDoesNotExist::TypeDoesNotExist()
	: err_msg_("Intern::TypeDoesNotExist")
	{}

const char* Intern::TypeDoesNotExist::what() const throw()
{
	return err_msg_;
}