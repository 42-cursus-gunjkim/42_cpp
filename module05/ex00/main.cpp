#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat("what", 151);
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat gunjoong = Bureaucrat("gunjoong", 32);
		gunjoong.increase();
		std::cout << gunjoong << std::endl;
		gunjoong.increase();
		std::cout << gunjoong << std::endl;
		gunjoong.decrease();
		std::cout << gunjoong << std::endl;
		Bureaucrat lim = Bureaucrat("lim", 1);
		lim.increase();
		Bureaucrat kim = Bureaucrat("kim", 150);
		kim.decrease();
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}