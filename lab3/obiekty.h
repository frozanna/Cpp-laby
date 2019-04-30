#ifndef OBIEKTY_H
#define OBIEKTY_H

class Pojazd{
    const std::string marka; // tu const?
    int przebieg;
    float cena;
public:
    Pojazd(const std::string marka = "brak", int przebieg = 0, float cena = 0.0): marka(marka), przebieg(przebieg),cena(cena){};
};

class Komis{
    Pojazd *pojazdy;
    int rozmiar;
    int licznik;
public:
    Komis(int rozmiar = 10);
    Komis(const Komis &zrodlo);
    Komis &operator=(const Komis &zrodlo);
    Komis(Komis &&zrodlo);
    Komis &operator=(Komis &&zrodlo);
    int get_licznik() const{return licznik;} ;
    void add_pojazd(const Pojazd pojazd);
    ~Komis(){delete [] pojazdy;};
};


#endif //OBIEKTY_H
