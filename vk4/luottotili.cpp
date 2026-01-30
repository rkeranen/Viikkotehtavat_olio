#include "Luottotili.h"

Luottotili::Luottotili(const std::string& nimi, double raja)
    : Pankkitili(nimi), luottoRaja(raja) {}

bool Luottotili::deposit(double amount) {
    if (amount < 0.0) return false;
    if (saldo + amount > 0.0) return false;
    saldo += amount;
    return true;
}

bool Luottotili::withdraw(double amount) {
    if (amount < 0.0) return false;
    double uusiSaldo = saldo - amount;
    if (uusiSaldo < -luottoRaja) return false;
    saldo = uusiSaldo;
    return true;
}
