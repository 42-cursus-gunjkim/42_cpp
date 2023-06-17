#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(Contact &c)
{
	this->first_name = c.first_name;
	this->last_name = c.last_name;
	this->nick_name = c.nick_name;
	this->phone_number = c.phone_number;
	this->darkest_secret = c.darkest_secret;
}

Contact &Contact::operator=(Contact &c)
{
	this->first_name = c.first_name;
	this->last_name = c.last_name;
	this->nick_name = c.nick_name;
	this->phone_number = c.phone_number;
	this->darkest_secret = c.darkest_secret;
	return *this;
}

void Contact::setFirstName(std::string &first_name) { this->first_name = first_name; };
void Contact::setLastName(std::string &last_name) { this->last_name = last_name; };
void Contact::setNickName(std::string &nick_name) { this->nick_name = nick_name; };
void Contact::setPhoneNumber(std::string &phone_number) { this->phone_number = phone_number; };
void Contact::setDarkestSecret(std::string &darkest_secret) { this->darkest_secret = darkest_secret; };

const std::string Contact::getFirstName() const { return this->first_name; }
const std::string Contact::getLastName() const { return this->last_name; }
const std::string Contact::getNickName() const { return this->nick_name; }
const std::string Contact::getPhoneNumber() const { return this->phone_number; };
const std::string Contact::getDarkestSecret() const { return this->darkest_secret; };
