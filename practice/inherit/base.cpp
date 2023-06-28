#include <iostream>
#include <string>

class Base {

protected:
    std::string parent_string;

public:
    Base() : parent_string("기반") { std::cout << "기반클래스" << std::endl; }

    virtual void what() { std::cout << parent_string << std::endl; }
};

class Derived : public Base {

private:
    std::string s;

public:
    Derived() : Base(), s("파생") {
        std::cout << "파생 클래스" << std::endl;
    }

    void what() { std::cout << s << std::endl; }
};

int main() {
    Base *p;
    Derived d;

    p = &d;

    p->what();
}