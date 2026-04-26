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

bool Employee::operator<(const Employee& other) const {
    return this->name < other.name;
}

int Employee::operator%(int divisor) const {
    return static_cast<int>(this->salary) % divisor;
}

bool Employee::operator==(const Employee& other) const {
    return this->name == other.name && this->salary == other.salary;
}
