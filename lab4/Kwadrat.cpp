#include <iostream>
#include "Kwadrat.h"

using namespace std;

namespace lab4{

    std::string Kwadrat::opis() const {
        return Figura::opis() + ", a: " + to_string(a);
    }

    bool Kwadrat::zapisz(std::ostream &os) const {
        if(!Figura::zapisz(os)) return false;
        os << " " << a;
        if(os.good()) return true;
        return false;
    }

    bool Kwadrat::wczytaj(std::istream &is) {
        if(!Figura::wczytaj(is)) return false;
        cout << "a: ";
        is >> a;
        b = a;
        if(is.good()) return true;
        return false;
    }


}