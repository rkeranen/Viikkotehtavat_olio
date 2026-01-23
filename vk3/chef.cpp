#include "chef.h"
#include <iostream>

Chef::Chef(std::string name) : chefName(name) {
    std::cout << "Chef " << chefName << " konstruktori" << std::endl;
}

Chef::~Chef() {
    std::cout << "Chef " << chefName << " destruktori" << std::endl;
}

std::string Chef::getName() {
    return chefName;
}

int Chef::makeSalad(int ingredients) {
    return ingredients / 5;
}

int Chef::makeSoup(int ingredients) {
    return ingredients / 3;
}
