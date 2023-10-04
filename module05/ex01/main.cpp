#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try
	{
		Form f("form", 121, 50);
		Bureaucrat gunjoong("gunjoon", 149);
		gunjoong.signForm(f);
		std::cout << gunjoong << std::endl;
		gunjoong.decrease();
		std::cout << gunjoong << std::endl;
		gunjoong.decrease();
		std::cout << gunjoong << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}