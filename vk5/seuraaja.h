#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>
#include <iostream>

class Seuraaja {
private:
    std::string nimi;

public:
    Seuraaja* next = nullptr;

    // Konstruktori
    Seuraaja(std::string n);

    // Jäsenfunktiot
    std::string getNimi();
    void paivitys(std::string viesti);
};

#endif
