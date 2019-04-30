#ifndef CPP4_KOLO_H
#define CPP4_KOLO_H

#include <iostream>
#include <math.h>
#include "Figura.h"

namespace lab4{
    class Kolo : public Figura{
    protected:
        double promien;
    public:
        Kolo() = delete;
        Kolo(const Punkt &_srodek,const std::string &_etykieta, double _promien):Figura(_srodek,_etykieta),promien(_promien){};
        ~Kolo() override { std::cout << "Destroying Kolo." << std::endl; };
        std::string opis() const  override;
        double pole() const override { return M_PI*promien*promien; };
        bool zapisz(std::ostream &os) const  override;
        bool wczytaj(std::istream &is)  override;
    };
}


#endif //CPP4_KOLO_H
