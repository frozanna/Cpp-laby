#include <iostream>
#include <sstream>
#include "Figura.h"


using namespace std;

namespace lab4{

    string Figura::opis() const{
        ostringstream stream;
        stream << srodek;
        return "srodek: " + stream.str() + ", etykieta: " + etykieta;
    }

    bool Figura::zapisz(std::ostream &os) const {
        if(!srodek.zapisz(os)) return false;
        os << etykieta;
        if(os.good()) return true;
        return false;
    }

    bool Figura::wczytaj(std::istream &is) {
        if(!srodek.wczytaj(is)) return false;
        cout << "Etykieta: ";
        is >> etykieta;
        if(is.good()) return true;
        return false;
    }

}