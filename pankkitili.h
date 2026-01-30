#include <string>
#pragma once

class Pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    explicit Pankkitili(const std::string& nimi);
    virtual ~Pankkitili() = default;

    double getBalance() const;

    virtual bool deposit(double amount);   // talletus
    virtual bool withdraw(double amount);  // nosto
};
