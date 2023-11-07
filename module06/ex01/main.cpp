#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data test = { "kim gunjoong", 26, 0.1, 0.3 };

	uintptr_t uptr = Serializer::serialize(&test);
	Data* dptr = Serializer::deserialize(uptr);

	std::cout 
	<< "Data" << std::endl
	<< "name : " << dptr->name << std::endl
	<< "age : " << dptr->age << std::endl
	<< "left vision : " << dptr->leftVision << std::endl
	<< "right vision : " << dptr->rightVision << std::endl;

	return 0;
}