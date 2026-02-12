#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include "Student.h"

int main() {
    int selection = 0;
    std::vector<Student> studentList;

    do {
        std::cout << "Select" << std::endl;
        std::cout << "Add students = 0" << std::endl;
        std::cout << "Print all students = 1" << std::endl;
        std::cout << "Sort and print students according to Name = 2" << std::endl;
        std::cout << "Sort and print students according to Age = 3" << std::endl;
        std::cout << "Find and print student = 4" << std::endl;

        std::cin >> selection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (selection) {

        case 0: {
            std::string name;
            int age;

            std::cout << "Student name ?" << std::endl;
            std::getline(std::cin, name);

            std::cout << "Student age ?" << std::endl;
            std::cin >> age;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            studentList.emplace_back(name, age);
            break;
        }

        case 1: {
            for (const auto& s : studentList) {
                s.printStudentInfo();
            }
            break;
        }

        case 2: {
            std::vector<Student> sorted = studentList;

            std::sort(sorted.begin(), sorted.end(),
                      [](const Student& a, const Student& b) {
                          return a.getName() < b.getName();
                      });

            for (const auto& s : sorted) {
                s.printStudentInfo();
            }
            break;
        }

        case 3: {
            std::vector<Student> sorted = studentList;

            std::sort(sorted.begin(), sorted.end(),
                      [](const Student& a, const Student& b) {
                          return a.getAge() < b.getAge();
                      });

            for (const auto& s : sorted) {
                s.printStudentInfo();
            }
            break;
        }

        case 4: {
            std::string searchName;
            std::cout << "Student to be found name = ?" << std::endl;
            std::getline(std::cin, searchName);

            auto it = std::find_if(studentList.begin(), studentList.end(),
                                   [&](const Student& s) {
                                       return s.getName() == searchName;
                                   });

            if (it != studentList.end()) {
                std::cout << "Student found:" << std::endl;
                it->printStudentInfo();
            }
            break;
        }

        default:
            std::cout << "Wrong selection, stopping..." << std::endl;
            break;
        }

    } while (selection < 5);

    return 0;
}
