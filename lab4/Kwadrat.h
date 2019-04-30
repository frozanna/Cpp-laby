#ifndef CPP4_KWADRAT_H
#define CPP4_KWADRAT_H

#include <iostream>
#include "Prostokat.h"

namespace lab4{

    class Kwadrat : public Prostokat{
    public:
        Kwadrat() = delete;
        Kwadrat(const Punkt &_srodek,const std::string &_etykieta, double _a):Prostokat(_srodek,_etykieta,_a,_a){};
        ~Kwadrat() override { std::cout << "Destroying Kwadrat." << std::endl; };
        std::string opis() const override;
        bool zapisz(std::ostream &os) const override;
        bool wczytaj(std::istream &is) override;
    };

}


#endif //CPP4_KWADRAT_H
