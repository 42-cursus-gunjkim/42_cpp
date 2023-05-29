#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	~Contact();
	Contact(Contact &c);
	Contact &operator=(Contact &c);
	void setFirstName(std::string &_firstName);
	void setLastName(std::string &_lastName);
	void setNickName(std::string &_nickName);
	void setPhoneNumber(std::string &_phoneNumber);
	void setDarkestSecret(std::string &_darkedstSecret);
	const std::string &getFirstName();
	const std::string &getLastName();
	const std::string &getNickName();
	const std::string &getPhoneNumber();
	const std::string &getDarkestSecret();
};

#endif
