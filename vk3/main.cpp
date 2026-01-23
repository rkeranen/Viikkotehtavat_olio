#include <iostream>
#include "chef.h"
#include "italianchef.h"

int main() {
    Chef g("Gordon");
    std::cout << "Chef " << g.getName()
              << " with 11 items can make salad "
              << g.makeSalad(11) << " portions" << std::endl;

    std::cout << "Chef " << g.getName()
              << " with 14 items can make soup "
              << g.makeSoup(14) << " portions" << std::endl;

    std::cout << std::endl;

    ItalianChef im("Mario");

    std::cout << "Chef " << im.getName()
              << " with 9 items can make salad "
              << im.makeSalad(9) << " portions" << std::endl;

    im.askSecret("pizza", 12, 12);
    return 0;
}
