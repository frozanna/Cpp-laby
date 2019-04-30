#ifndef CPP4_PROSTOKAT_H
#define CPP4_PROSTOKAT_H

#include <iostream>
#include "Figura.h"

namespace lab4{
    class Prostokat : public Figura {
    protected:
        double a,b;
    public:
        Prostokat() = delete;
        Prostokat(const Punkt &_srodek,const std::string &_etykieta, double _a, double _b):Figura(_srodek,_etykieta),a(_a),b(_b) {};
        virtual ~Prostokat() { std::cout << "Destroying Prostokat." << std::endl; };
        virtual std::string opis() const;
        double pole() const  override { return a*b; };
        virtual bool zapisz(std::ostream &os) const;
        virtual bool wczytaj(std::istream &is);
    };

}



#endif //CPP4_PROSTOKAT_H
