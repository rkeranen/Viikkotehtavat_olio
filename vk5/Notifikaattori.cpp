#include "Notifikaattori.h"
using namespace std;

Notifikaattori::Notifikaattori() {
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja* s) {
    cout << "Notifikaattori lisaa seuraajan " << s->getNimi() << endl;
    s->next = seuraajat;
    seuraajat = s;
}

void Notifikaattori::poista(Seuraaja* s) {
    cout << "Notifikaattori poistaa seuraajan " << s->getNimi() << endl;

    if (seuraajat == s) {
        seuraajat = seuraajat->next;
        return;
    }

    Seuraaja* o = seuraajat;
    while (o != nullptr) {
        if (o->next == s) {
            o->next = s->next;
            return;
        }
        o = o->next;
    }
}

void Notifikaattori::tulosta() {
    cout << "Notifikaattorin seuraajat:" << endl;
    Seuraaja* o = seuraajat;
    while (o != nullptr) {
        cout << "Seuraaja " << o->getNimi() << endl;
        o = o->next;
    }
}

void Notifikaattori::postita(string viesti) {
    cout << "Notifikaattori postaa viestin " << viesti << endl;
    Seuraaja* o = seuraajat;
    while (o != nullptr) {
        o->paivitys(viesti);
        o = o->next;
    }
}
