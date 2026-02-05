#include "Seuraaja.h"
using namespace std;

Seuraaja::Seuraaja(string n) : nimi(n) {
    cout << "Luodaan seuraaja " << nimi << endl;
}

string Seuraaja::getNimi() {
    return nimi;
}

void Seuraaja::paivitys(string viesti) {
    cout << "Seuraaja " << nimi << " sai viestin " << viesti << endl;
}
