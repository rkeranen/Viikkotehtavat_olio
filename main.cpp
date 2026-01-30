#include "Asiakas.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(0);

    Asiakas a("Aapeli", 1000);
    std::cout << "Pankkitili luotu Aapelille\n";
    std::cout << "Luottotili luotu Aapelille, luottoraja " << a.getLuottoRaja() << "\n";
    std::cout << "Asiakkuus luotu Aapeli\n";
    a.showSaldoJaljella();
    std::cout << "\n";

    Asiakas b("Bertta", 1000);
    std::cout << "Pankkitili luotu Berttalle\n";
    std::cout << "Luottotili luotu Berttalle, luottoraja " << b.getLuottoRaja() << "\n";
    std::cout << "Asiakkuus luotu Bertta\n";
    b.showSaldoJaljella();
    std::cout << "\n";

    a.talletus(250);
    std::cout << "Pankkitili: talletus 250 tehty\n";
    a.luotonNosto(150);
    std::cout << "Luottotili: nosto 150 tehty, luottoa jaljella " << a.getLuottoJaljella() << "\n";
    a.showSaldoJaljella(); // 250 / 850
    std::cout << "\n";

    std::cout << "Aapeli\n";
    a.showSaldoJaljella();
    std::cout << "\nBertta\n";
    b.showSaldoJaljella();
    std::cout << "\n";

    bool siirtoOk = a.tiliSiirto(50, b);
    std::cout << "Pankkitili: Aapeli siirtaa 50 Bertalle: " << (siirtoOk ? "tehty" : "epäonnistui") << "\n";
    if (siirtoOk) {
        std::cout << "Aapeli Pankkitili: nosto 50 tehty\n";
        std::cout << "Bertta Pankkitili: talletus 50 tehty\n";
    }
    std::cout << "\n";

    std::cout << "Bertta\n";
    b.showSaldoJaljella();
    std::cout << "\n";

    std::cout << "Lopputilanne\n";
    std::cout << "Aapeli\n";
    a.showSaldoJaljella();
    std::cout << "\nBertta\n";
    b.showSaldoJaljella();

    return 0;
}
