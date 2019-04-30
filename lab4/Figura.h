#ifndef CPP4_FIGURA_H
#define CPP4_FIGURA_H

#include <iostream>
#include "Punkt.h"

namespace lab4{
    class Figura {
    protected:
        Punkt srodek;
        std::string etykieta;
    public:
        Figura() = delete;
        Figura(const Punkt &_srodek,const std::string &_etykieta):srodek(_srodek),etykieta(_etykieta){};
        virtual ~Figura() { std::cout << "Destroying Figura." << std::endl;};
        void przesun(const Punkt &sr) { srodek = sr; };
        virtual std::string opis() const;
        virtual double pole() const = 0;
        virtual bool zapisz(std::ostream &os) const;
        virtual bool wczytaj(std::istream &is);
    };
}


#endif //CPP4_FIGURA_H
