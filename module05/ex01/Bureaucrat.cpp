#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
	if (grade < highest_grade_)
		throw GradeTooHighException();
	else if (grade > lowest_grade_)
		throw GradeTooLowException();
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
{
	const_cast<std::string &>(this->name_) = b.name_;
	this->grade_ = b.grade_;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this == &b)
		return (*this);
	const_cast<std::string &>(this->name_) = b.name_;
	this->grade_ = b.grade_;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return this->name_;
}

int Bureaucrat::getGrade() const
{
	return this->grade_;
}

void Bureaucrat::increase()
{
	if (grade_ == highest_grade_)
		throw GradeTooHighException("Bureaucrat::GradeTooHighException : Too high to increase!");
	this->grade_--;
}

void Bureaucrat::decrease()
{
	if (grade_ == lowest_grade_)
		throw GradeTooLowException("Bureaucrat::GradeTooLowException : Too low to decrease!");
	this->grade_++;
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cout 
		<< this->name_ 
		<< " couldn't sign " << f.getName() 
		<< " because " << e.what() << std::endl;
		return;
 	}
	std::cout << this->name_ 
	<< " signed " << f.getName() << std::endl; 
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
	: err_msg_("Bureaucrat::GradeTooHighException : Highest = 1, Lowest = 150") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* err_msg)
	: err_msg_(err_msg) {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return err_msg_;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
	: err_msg_("Bureaucrat::GradeTooLowException : Highest = 1, Lowest = 150") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* err_msg)
	: err_msg_(err_msg) {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return err_msg_;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return out; 
}
