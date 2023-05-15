#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(Contact &c)
{
	firstName = c.firstName;
	lastName = c.lastName;
	nickName = c.nickName;
}

Contact &Contact::operator=(Contact &c)
{
	firstName = c.firstName;
	lastName = c.lastName;
	nickName = c.nickName;
	return *this;
}

void Contact::setContact(std::string &_firstName, std::string &_lastName, std::string &_nickName)
{
	firstName = _firstName;
	lastName = _lastName;
	nickName = _nickName;
}

const std::string &Contact::getFirstName() { return firstName; }
const std::string &Contact::getLastName() { return lastName; }
const std::string &Contact::getNickName() { return nickName; }
