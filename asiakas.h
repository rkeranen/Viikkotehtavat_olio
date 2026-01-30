#include <string>
#include "Pankkitili.h"
#include "Luottotili.h"
#pragma once

class Asiakas {
private:
    std::string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(const std::string& nimi, double luottoRaja);

    std::string getNimi() const;
    double getKayttoSaldo() const;
    double getLuottoSaldo() const;
    double getLuottoRaja() const;
    double getLuottoJaljella() const;

    void showSaldo() const;
    void showSaldoJaljella() const;

    bool talletus(double amount);
    bool nosto(double amount);

    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);

    bool tiliSiirto(double amount, Asiakas& vastaanottaja);
};
