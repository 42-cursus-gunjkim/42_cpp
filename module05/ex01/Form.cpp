#include "Form.hpp"

Form::Form(const std::string& name)
	: name_(name)
	, is_signed_(false)
	, signable_(lowest_grade_)
	, executable_(lowest_grade_) {}

Form::Form(const std::string& name, int signable, int executable)
	: name_(name)
	, is_signed_(false)
	, signable_(signable)
	, executable_(executable)
{
	if (this->signable_ < highest_grade_ || this->executable_ < highest_grade_)
		throw GradeTooHighException();
	else if (this->signable_ > lowest_grade_ || this->executable_ > lowest_grade_)
		throw GradeTooLowException();
}

Form::Form(const Form& f)
	: name_(f.name_)
	, is_signed_(f.is_signed_)
	, signable_(f.signable_)
	, executable_(f.executable_) {}

Form::~Form() {}

const Form& Form::operator=(const Form& f)
{
	if (this == &f)
		return *this;
	const_cast<std::string&>(this->name_) = f.name_;
	this->is_signed_ = f.is_signed_;
	const_cast<int&>(this->signable_) = f.signable_;
	const_cast<int&>(this->executable_) = f.executable_;
	return *this;
}

std::string Form::getName() const
{
	return this->name_;
}

bool Form::getIsSigned() const
{
	return this->is_signed_;
}

int Form::getSignable() const
{
	return this->signable_;
}

int Form::getExecutable() const
{
	return this->executable_;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (this->signable_ < b.getGrade())
		throw GradeTooLowException("Form::GradeTooLowException : Grade is too low to sign!");
	this->is_signed_ = true;
}

Form::GradeTooHighException::GradeTooHighException()
	: err_msg_("Form::GradeTooHighException : Highest : 1, Lowest : 150") {}

Form::GradeTooHighException::GradeTooHighException(const char* err_msg)
	: err_msg_(err_msg) {}

Form::GradeTooLowException::GradeTooLowException()
	: err_msg_("Form::GradeTooLowException : Highest : 1, Lowest : 150") {}

Form::GradeTooLowException::GradeTooLowException(const char* err_msg)
	: err_msg_(err_msg) {}

const char* Form::GradeTooHighException::what() const throw()
{
	return this->err_msg_;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return this->err_msg_;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out
	<< "Form : " << f.getName() << std::endl
	<< "is signed? : " << f.getIsSigned() << std::endl
	<< "required grade to sign : " << f.getSignable() << std::endl
	<< "required grade to exec : " << f.getExecutable() << std::endl;
	return out;
}

