#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < 0)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {
	const_cast<std::string &>(this->name) = b.name;
	this->grade = b.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
	if (this == &b)
		return (*this);
	const_cast<std::string &>(this->name) = b.name;
	this->grade = b.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::increase() {
	if (grade == 1)
		throw GradeTooHighException();
	this->grade++;
}

void Bureaucrat::decrease() {
	if (grade == 150)
		throw GradeTooLowException();
	this->grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High Exception : Highest = 1, Lowest = 150";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Low High Exception : Highest = 1, Lowest = 150";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return out; 
}
