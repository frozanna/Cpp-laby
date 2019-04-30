#include <iostream>
#include "Kolo.h"

using namespace std;

namespace lab4{

    std::string Kolo::opis() const {
        return Figura::opis() + ", promien: " + to_string(promien);
    }

    bool Kolo::zapisz(std::ostream &os) const {
        if(!Figura::zapisz(os)) return false;
        os << " " << promien;
        if(os.good()) return true;
        return false;
    }

    bool Kolo::wczytaj(std::istream &is) {
        if(!Figura::wczytaj(is)) return false;
        cout << "Promien: ";
        is >> promien;
        if(is.good()) return true;
        return false;
    }

}