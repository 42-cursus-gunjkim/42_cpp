#include "Bureaucrat.hpp"

void check_leak() {
	system("leaks ex00");
}

int main() {
	try {
		Bureaucrat("what", 151);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat gunjoong = Bureaucrat("gunjoong", 32);
	gunjoong.increase();
	std::cout << gunjoong << std::endl;
	gunjoong.increase();
	std::cout << gunjoong << std::endl;
	gunjoong.decrease();
	std::cout << gunjoong << std::endl;

	Bureaucrat kim = Bureaucrat("kim", 1);
	try {
		kim.increase();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	atexit(check_leak);
	return 0;
}