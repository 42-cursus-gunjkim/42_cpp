#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;

public:
	Contact();
	~Contact();
	Contact(Contact &c);
	Contact &operator=(Contact &c);
	void setContact(std::string &_firstName, std::string &_lastName, std::string &_nickName);
	const std::string &getFirstName();
	const std::string &getLastName();
	const std::string &getNickName();
};

#endif
