#include <iostream>

class A {
public:
    int a;
    A() { std::cout << "A constructed" << std::endl; }
};

class B {
public:
    int a;
    B() { std::cout << "B constructed" << std::endl; }
};

class C: public A, public B {
public:
    int c;
    C() { std::cout << "C constructed" << std::endl; }
};

int main() {
    C c;
}
