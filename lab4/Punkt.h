#ifndef CPP4_PUNKT_H
#define CPP4_PUNKT_H

#include <iostream>

namespace lab4{
    class Punkt {
    private:
        double x,y;
    public:
        Punkt() = delete;
        Punkt(double _x, double _y): x(_x), y(_y){};
        void setX(double _x) { x = _x; };
        double getX() const { return x; };
        bool zapisz(std::ostream &os) const;
        bool wczytaj(std::istream &is);
        friend std::ostream &operator<<(std::ostream &out, const Punkt &p);
    };

}


#endif //CPP4_PUNKT_H
