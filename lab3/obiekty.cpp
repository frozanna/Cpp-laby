#include <iostream>
#include "obiekty.h"

using namespace std;

Komis::Komis(int rozmiar_arg){
    if(rozmiar_arg <= 0){
        string exception = "Size must be greater than 0.\n";
        throw exception;
    }
    rozmiar = rozmiar_arg;
    licznik = 0;
    pojazdy = new Pojazd[rozmiar_arg];
}

Komis::Komis(const Komis &zrodlo) {
    rozmiar = zrodlo.rozmiar;
    licznik = zrodlo.licznik;
    pojazdy = new Pojazd[zrodlo.rozmiar];
    std::copy(zrodlo.pojazdy,zrodlo.pojazdy+licznik,pojazdy);
}

Komis::Komis(Komis &&zrodlo) {
    rozmiar = zrodlo.rozmiar;
    licznik = zrodlo.licznik;
    pojazdy = zrodlo.pojazdy;
    zrodlo.licznik = 0;
    zrodlo.rozmiar = 0;
    zrodlo.pojazdy = nullptr;
}

Komis &Komis::operator=(const Komis &zrodlo) {
    if(this != &zrodlo){
        delete [] pojazdy;
        rozmiar = zrodlo.rozmiar;
        licznik = zrodlo.licznik;
        pojazdy = new Pojazd[zrodlo.rozmiar];
        std::copy(zrodlo.pojazdy,zrodlo.pojazdy+licznik,pojazdy);
    }
    return *this;
}

Komis &Komis::operator=(Komis &&zrodlo) {
    if (this != &zrodlo){
        delete [] pojazdy;
        rozmiar = zrodlo.rozmiar;
        licznik = zrodlo.licznik;
        pojazdy = zrodlo.pojazdy;
        zrodlo.licznik = 0;
        zrodlo.rozmiar = 0;
        zrodlo.pojazdy = nullptr;
    }
    return *this;
}

void Komis::add_pojazd(const Pojazd pojazd) {
    if(licznik >= rozmiar){
        string exception = "Not more place in array.\n";
        throw exception;
    }
    pojazdy[licznik] = pojazd;
    licznik++;
}