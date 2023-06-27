
#include <string>
#include <iostream>

class Employee {
    std::string name;
    int age;

    std::string position;
    int rank;

public :
    Employee(std::string name, int age, std::string position, int rank) 
        : name(name), age(age), position(position), rank(rank) {}
    
    Employee(const Employee &e) {
        this->name = e.name;
        this->age = e.age;
        this->position = e.position;
        this->rank = e.rank;
    }

    Employee() {}

    void printInfo() {
        std::cout
            << "name : " << this->name << std::endl
            << "position : " << this->position << std::endl
            << "age : " << this->age << std::endl
            << "wage : " << calculatePay() << "won" << std::endl;
    }

    int calculatePay() { return 200 + this->rank * 50;} 
};

class Manager : public Employee {
    int year_of_service;

public:
    Manager(std::string name, int age, std::string position, int rank, int year)
        : year_of_service
};

class EmployeeList {
    int alloc_employee;
    int current_employee;
    Employee **employee_list;

public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
        employee_list = new Employee*[alloc_employee];
        current_employee = 0;
    }

    ~EmployeeList() {
        for (int i = 0; i < current_employee; i++) {
            delete employee_list[i];
        }
        delete[] employee_list;
    }

    void addEmployee(Employee *employee) {
        employee_list[current_employee] = employee;
        current_employee++;
    }

    int getCurrentEmployee() { return this->current_employee; }

    void printEmployeeInfo() {
        int total_pay = 0;
        for (int i = 0; i < current_employee; i++) {
            employee_list[i]->printInfo();
            total_pay += employee_list[i]->calculatePay();
        }
        std::cout << "total pay : " << total_pay << std::endl;
    }
};

int main() {
  EmployeeList emp_list(10);
  emp_list.addEmployee(new Employee("노홍철", 34, "평사원", 1));
  emp_list.addEmployee(new Employee("하하", 34, "평사원", 1));

  emp_list.addEmployee(new Employee("유재석", 41, "부장", 7));
  emp_list.addEmployee(new Employee("정준하", 43, "과장", 4));
  emp_list.addEmployee(new Employee("박명수", 43, "차장", 5));
  emp_list.addEmployee(new Employee("정형돈", 36, "대리", 2));
  emp_list.addEmployee(new Employee("길", 36, "인턴", -2));
  emp_list.printEmployeeInfo();
  return 0;
}