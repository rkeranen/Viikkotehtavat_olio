#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include <string>
#include <iostream>
#include "Seuraaja.h"

class Notifikaattori {
private:
    Seuraaja* seuraajat = nullptr;

public:
    Notifikaattori();

    void lisaa(Seuraaja* s);
    void poista(Seuraaja* s);
    void tulosta();
    void postita(std::string viesti);
};

#endif
