#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat gunjoong("gunjoong", 1);
		AForm *s = new ShrubberyCreationForm("scf");
		AForm *r = new RobotomyRequestForm("rrf");
		AForm *p = new PresidentialPardonForm("ppf");
		gunjoong.signForm(*s);
		gunjoong.executeForm(*s);
		gunjoong.signForm(*r);
		gunjoong.executeForm(*r);
		gunjoong.signForm(*p);
		gunjoong.executeForm(*p);
		std::cout << *p << std::endl;
		delete s;
		delete r;
		delete p;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}