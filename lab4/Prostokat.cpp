#include <iostream>
#include "Prostokat.h"

using namespace std;

namespace lab4{

    string Prostokat::opis() const {
        return Figura::opis() + ", a: " + to_string(a) + ", b: " + to_string(b);
    }

    bool Prostokat::zapisz(std::ostream &os) const{
        if(!Figura::zapisz(os)) return false;
        os << " " << a << " " << b;
        if(os.good()) return true;
        return false;
    }

    bool Prostokat::wczytaj(std::istream &is) {
        if(!Figura::wczytaj(is)) return false;
        cout << "a: ";
        is >> a;
        cout << "v: ";
        is >> b;
        if(is.good()) return true;
        return false;
    }


}