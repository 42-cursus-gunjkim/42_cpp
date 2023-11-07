#include <ctime>
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int random = rand() % 3;
	std::cout << "random " << random << std::endl;

	switch(random)
	{
		case 0:
		{
			A* a = new A();
			return dynamic_cast<Base*>(a);
			break;
		}
		case 1:
		{
			B* b = new B();
			return dynamic_cast<Base*>(b);
			break;
		}
		case 2:
		{
			C* c = new C();
			return dynamic_cast<Base*>(c);
			break;
		}
		default:
			return (NULL);
			break;
	}
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p) != NULL)
		std::cout << "Actual Type : A" << std::endl;
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << "Actual Type : B" << std::endl;
	else if(dynamic_cast<C*>(p) != NULL)
		std::cout << "Actual Type : C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Actual Type : A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "Actual Type : B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "Actual Type : C" << std::endl;
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
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Base* b = generate();
		identify(b);
		delete b;
	}

	for (int i = 0; i < 5; i++)
	{
		Base& b = *generate();
		identify(b);
	}
}