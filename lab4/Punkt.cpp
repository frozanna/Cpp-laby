#include <iostream>
#include "Punkt.h"

using namespace std;

namespace lab4{

    bool Punkt::zapisz(ostream &os) const {
        os << "(" << x << "," << y << ") ";
        if(os.good()) return true;
        return false;
    }

    bool Punkt::wczytaj(istream &is) {
        cout << "x: ";
        is >> x;
        cout << "y: ";
        is >> y;
        if(is.good()) return true;
        return false;
    }

    ostream &operator<<(ostream &out, const lab4::Punkt &p) {
        return out << "(" << p.x << "," << p.y << ")";
    }
}