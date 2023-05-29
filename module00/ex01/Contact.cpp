#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(Contact &c)
{
	firstName = c.firstName;
	lastName = c.lastName;
	nickName = c.nickName;
	phoneNumber = c.phoneNumber;
	darkestSecret = c.darkestSecret;
}

Contact &Contact::operator=(Contact &c)
{
	firstName = c.firstName;
	lastName = c.lastName;
	nickName = c.nickName;
	phoneNumber = c.phoneNumber;
	darkestSecret = c.darkestSecret;
	return *this;
}

void Contact::setFirstName(std::string &_firstName) { firstName = _firstName; };
void Contact::setLastName(std::string &_lastName) { lastName = _lastName; };
void Contact::setNickName(std::string &_nickName) { nickName = _nickName; };
void Contact::setPhoneNumber(std::string &_phoneNumber) { phoneNumber = _phoneNumber; };
void Contact::setDarkestSecret(std::string &_darkestSecret) { darkestSecret = _darkestSecret; };

const std::string &Contact::getFirstName() { return firstName; }
const std::string &Contact::getLastName() { return lastName; }
const std::string &Contact::getNickName() { return nickName; }
const std::string &Contact::getPhoneNumber() { return phoneNumber; };
const std::string &Contact::getDarkestSecret() { return darkestSecret; };
