#include "AForm.hpp"

AForm::AForm(const std::string& name)
	: name_(name)
	, is_signed_(false)
	, signable_(lowest_grade_)
	, executable_(lowest_grade_) {}

AForm::AForm(const std::string& name, int signable, int executable)
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

AForm::AForm(const AForm& f)
	: name_(f.name_)
	, is_signed_(f.is_signed_)
	, signable_(f.signable_)
	, executable_(f.executable_) {}

AForm::~AForm() {}

const AForm& AForm::operator=(const AForm& f)
{
	if (this == &f)
		return *this;
	const_cast<std::string&>(this->name_) = f.name_;
	this->is_signed_ = f.is_signed_;
	const_cast<int&>(this->signable_) = f.signable_;
	const_cast<int&>(this->executable_) = f.executable_;
	return *this;
}

std::string AForm::getName() const
{
	return this->name_;
}

bool AForm::getIsSigned() const
{
	return this->is_signed_;
}

int AForm::getSignable() const
{
	return this->signable_;
}

int AForm::getExecutable() const
{
	return this->executable_;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (this->signable_ < b.getGrade())
		throw GradeTooLowException("Form::GradeTooLowException : Grade is too low to sign!");
	this->is_signed_ = true;
}

AForm::GradeTooHighException::GradeTooHighException()
	: err_msg_("Form::GradeTooHighException : Highest : 1, Lowest : 150") {}

AForm::GradeTooHighException::GradeTooHighException(const char* err_msg)
	: err_msg_(err_msg) {}

AForm::GradeTooLowException::GradeTooLowException()
	: err_msg_("Form::GradeTooLowException : Highest : 1, Lowest : 150") {}

AForm::GradeTooLowException::GradeTooLowException(const char* err_msg)
	: err_msg_(err_msg) {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return this->err_msg_;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return this->err_msg_;
}

AForm::FormNotSignedException::FormNotSignedException()
	: err_msg_("Form::FormNotSignedException : Form have to be signed before exec!")
	{}

const char* AForm::FormNotSignedException::what() const throw()
{
	return this->err_msg_;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out
	<< "Form : " << f.getName() << std::endl
	<< "is signed? : " << f.getIsSigned() << std::endl
	<< "required grade to sign : " << f.getSignable() << std::endl
	<< "required grade to exec : " << f.getExecutable() << std::endl;
	return out;
}

