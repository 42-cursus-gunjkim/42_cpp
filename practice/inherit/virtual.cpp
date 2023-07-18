#include <iostream>

class Parent {
public:
    Parent() { std::cout << "Parent constructor" << std::endl; }
    ~Parent() { std::cout << "Parent destructor" << std::endl; }
    //virtual void what() { std::cout << "im parent" << std::endl; }
};

class Child : public Parent {
public:
    Child() : Parent() { std::cout << "Child constructor" << std::endl; }
    ~Child() { std::cout << "Child destructor" << std::endl; }
    void what() { std::cout << "can you access?" << std::endl; }
    void hey() { std::cout << "hey" << std::endl; }
};

int main() {
    // std::cout << "--- normal child ---" << std::endl;
    // { Child c; }
    // std::cout << "--- pointing child by parent pointer ---" << std::endl;
    // {
    //     Parent *p = new Child();
    //     delete p;
    // }

    Parent a;
    Child b;

    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
}