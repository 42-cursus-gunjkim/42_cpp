#include "Bureaucrat.hpp"

void checkLeak()
{
	system("leaks ex00");
}

int main()
{
	try
	{
		Bureaucrat("what", 151);
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat gunjoong = Bureaucrat("gunjoong", 32);
	gunjoong.increase();
	std::cout << gunjoong << std::endl;
	gunjoong.increase();
	std::cout << gunjoong << std::endl;
	gunjoong.decrease();
	std::cout << gunjoong << std::endl;

	try
	{
		Bureaucrat kim = Bureaucrat("kim", 151);
		kim.decrease();
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	atexit(checkLeak);
	return 0;
}