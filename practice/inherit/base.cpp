#include <iostream>
#include <string>

class Base {

protected:
    std::string parent_string;

public:
    Base() : parent_string("기반") { std::cout << "기반클래스" << std::endl; what(); }

    void what() { std::cout << parent_string << std::endl; }
};

class Derived : public Base {
    std::string s;

public:
    Derived() : Base(), s("파생") {
        std::cout << "파생 클래스" << std::endl;
        parent_string="바꿔줘";
        what();
    }

    // void what() { std::cout << s << std::endl; }
};

int main() {
    std::cout << " === base === " << std::endl;
    Base p;

    std::cout << " === derived === " << std::endl;
    Derived d;
}