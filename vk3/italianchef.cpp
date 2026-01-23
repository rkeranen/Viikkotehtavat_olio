#include "italianchef.h"
#include <iostream>

ItalianChef::ItalianChef(std::string name) : Chef(name) {
    std::cout << "ItalianChef " << chefName << " konstruktori" << std::endl;
}

ItalianChef::~ItalianChef() {
    std::cout << "ItalianChef " << chefName << " destruktori" << std::endl;
}

bool ItalianChef::askSecret(std::string pwd, int flourIn, int waterIn) {
    if (pwd == password) {
        std::cout << "Password ok!" << std::endl;
        makePizza(flourIn, waterIn);
        return true;
    }
    return false;
}

int ItalianChef::makePizza(int flourIn, int waterIn) {
    int pizzasFromFlour = flourIn / 5;
    int pizzasFromWater = waterIn / 5;
    int pizzas = (pizzasFromFlour < pizzasFromWater) ? pizzasFromFlour : pizzasFromWater;

    std::cout << "ItalianChef " << chefName
              << " with " << flourIn << " flour and " << waterIn
              << " water can make " << pizzas << " pizzas" << std::endl;

    return pizzas;
}
