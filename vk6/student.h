#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {
private:
    std::string Name;
    int Age;

public:
    Student(const std::string& name, int age);
    void setName(const std::string& name);
    void setAge(int age);

    std::string getName() const;
    int getAge() const;

    void printStudentInfo() const;
};

#endif
