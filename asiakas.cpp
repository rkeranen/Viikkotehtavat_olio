#include "Asiakas.h"
#include <iostream>

Asiakas::Asiakas(const std::string& n, double raja)
    : nimi(n), kayttotili(n), luottotili(n, raja) {}

std::string Asiakas::getNimi() const { return nimi; }
double Asiakas::getKayttoSaldo() const { return kayttotili.getBalance(); }
double Asiakas::getLuottoSaldo() const { return luottotili.getBalance(); }
double Asiakas::getLuottoRaja() const { return luottotili.getCreditLimit(); }

double Asiakas::getLuottoJaljella() const {
    return luottotili.getCreditLimit() + luottotili.getBalance();
}

void Asiakas::showSaldo() const {
    std::cout << "Kayttotilin saldo " << kayttotili.getBalance() << "\n";
    std::cout << "Luottotilin saldo " << luottotili.getBalance() << "\n";
}

void Asiakas::showSaldoJaljella() const {
    std::cout << "Kayttotilin saldo " << kayttotili.getBalance() << "\n";
    std::cout << "Luottotilin saldo " << getLuottoJaljella() << "\n";
}

bool Asiakas::talletus(double amount) {
    return kayttotili.deposit(amount);
}

bool Asiakas::nosto(double amount) {
    return kayttotili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount) {
    return luottotili.deposit(amount);
}

bool Asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas& vastaanottaja) {
    if (amount < 0.0) return false;
    if (!kayttotili.withdraw(amount)) return false;
    if (!vastaanottaja.kayttotili.deposit(amount)) {
        kayttotili.deposit(amount);
        return false;
    }
    return true;
}
