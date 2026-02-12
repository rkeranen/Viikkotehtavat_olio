#include "Student.h"
#include <iostream>

Student::Student(const std::string& name, int age)
    : Name(name), Age(age)
{
}

void Student::setName(const std::string& name) {
    Name = name;
}

void Student::setAge(int age) {
    Age = age;
}

std::string Student::getName() const {
    return Name;
}

int Student::getAge() const {
    return Age;
}

void Student::printStudentInfo() const {
    std::cout << "Student " << Name << " Age " << Age << std::endl;
}
