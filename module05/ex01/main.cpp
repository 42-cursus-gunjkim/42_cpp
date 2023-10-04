#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try
	{
		Form f("form", 121, 50);
		Bureaucrat gunjoong("gunjoon", 122);
		gunjoong.signForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}