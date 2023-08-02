#include <iostream>
#include <string>

class A {
	protected:
		std::string type;
	public:
		A(std::string type) : type(type) {}
		A &operator=(const A &a) {
			std::cout << "A: operator=" << std::endl;
			type = a.type;
			return *this;
		}
		virtual void print() = 0;		
};

class B : public A {
	public:
		B(std::string type) : A(type) {}
		void print() {
			std::cout << "B: " << type << std::endl;
		}
};

int main() {
	B b("bbb");
	B c = b;
	b.print();
	c.print();
}