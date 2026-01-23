#ifndef CHEF_H
#define CHEF_H
#include <string>

class Chef {
public:
    Chef(std::string name);
    ~Chef();

    std::string getName();
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);

protected:
    std::string chefName;
};

#endif
