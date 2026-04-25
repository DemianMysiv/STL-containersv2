#pragma once
#include <string>

class Employee {
    double salary;
    std::string name;

public:

    Employee();
    Employee(double salary);
    Employee(std::string name, double salary);
    ~Employee() = default;

    double getSalary();
    std::string getName();

    double ChangeSalary(double newsalary);
    std::string ChangeName(std::string newname);

    bool operator<(const Employee& other) const {
        return this->name < other.name;
    }
};