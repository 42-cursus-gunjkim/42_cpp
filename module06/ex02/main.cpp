#include <ctime>
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	static unsigned long	seed = static_cast<unsigned long>(time(NULL));
	const unsigned long		a = 1103515245UL;
	const unsigned long		c = 12345UL;
	const unsigned long		m = 1UL << 31;

	seed = (a * seed + c) % m;
	int random = seed % 3;
	//std::cout << "random " << random << std::endl;

	switch(random)
	{
		case 0:
		{
			A* a = new A();
			return dynamic_cast<Base*>(a);
		}
		case 1:
		{
			B* b = new B();
			return dynamic_cast<Base*>(b);
		}
		case 2:
		{
			C* c = new C();
			return dynamic_cast<Base*>(c);
		}
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p) != NULL)
		std::cout << "Actual Type : A, Address : " << p << std::endl;
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << "Actual Type : B, Address : " << p << std::endl;
	else if(dynamic_cast<C*>(p) != NULL)
		std::cout << "Actual Type : C, Address : " << p << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Actual Type : A, Address : " << &a <<  std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "Actual Type : B, Address : " << &b << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "Actual Type : C, Address : " << &c << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Unknown type" << std::endl;
			}
			
		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		Base* b = generate();
		identify(b);
		delete b;
	}

	for (int i = 0; i < 5; i++)
	{
		Base* tmp = generate();
		Base& b = *tmp;
		identify(b);
		delete tmp;
	}
}