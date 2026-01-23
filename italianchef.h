#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"
#include <string>

class ItalianChef : public Chef {
public:
    ItalianChef(std::string name);
    ~ItalianChef();
    bool askSecret(std::string pwd, int flour, int water);

private:
    std::string password = "pizza";
    int flour = 0;
    int water = 0;

    int makePizza(int flour, int water);
};

#endif
