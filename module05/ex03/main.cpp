#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat gunjoong("gunjoong", 123);
		Intern someone;
		try
		{
			AForm* s_test = someone.makeForm("shrubbery create", "bender");
			AForm* r_test = someone.makeForm("robotomy request", "roboto");
			AForm* p_test = someone.makeForm("presidential pardon", "obama");

			try
			{
				gunjoong.signForm(*s_test);
				gunjoong.executeForm(*s_test);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				gunjoong.signForm(*r_test);
				gunjoong.executeForm(*r_test);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				gunjoong.signForm(*p_test);
				gunjoong.executeForm(*p_test);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}

			std::cout << *s_test << '\n';
			std::cout << *r_test << '\n';
			std::cout << *p_test << '\n';

			delete s_test;
			delete r_test;
			delete p_test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}