#pragma once
#include <string>s

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
};