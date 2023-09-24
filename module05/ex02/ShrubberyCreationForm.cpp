#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form(target, min_required_grade_to_sign, min_required_grade_to_exec)
	{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
	: Form(s.getName(), s.getSignable(), s.getExecutable())
	{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	if (this == &s)
		return (*this);
	dynamic_cast<Form&>(*this) = s;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
    if (executor.getGrade() > this->getExecutable())
		throw GradeTooLowException("Form::GradeTooLowException : Too low to exec!");

	// Open the file
	std::string filename = this->getName() + "_shrubbery";
	std::ofstream writer(filename.c_str());
	if (!writer.is_open())
	    throw std::ios_base::failure("Failed to open file: " + filename);

	// Draw ASCII tree
	writer << "    /\\    \n";
	writer << "   /  \\   \n";
	writer << "  /    \\  \n";
	writer << " /______\\ \n";
	writer << "   |  |   \n";
	writer << "   |  |   \n";
	writer.close();
}