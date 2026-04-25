#include "Employee.h"

Employee::Employee() : salary(0) {};
Employee::Employee(double salary) : salary(salary) {};
Employee::Employee(std::string name, double salary) : name(name), salary(salary) {};

double Employee::getSalary() {
    return salary;
}
std::string Employee::getName() {
    return name;
}

double Employee::ChangeSalary(double newsalary) {
    salary = newsalary;
    return salary;
}

std::string Employee::ChangeName(std::string newname) {
    name = newname;
    return name;
}