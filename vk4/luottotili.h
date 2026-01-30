#include "Pankkitili.h"
#pragma once

class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(const std::string& nimi, double raja);

    bool deposit(double amount) override;
    bool withdraw(double amount) override;

    double getCreditLimit() const { return luottoRaja; }
};
