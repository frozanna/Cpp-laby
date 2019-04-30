#include <iostream>
#include "obiekty.h"

using namespace std;

int main() {
    Komis komis = Komis(3);
    try{
        Komis komis1 = Komis(-1);
    } catch(std::string e) {
        cout<<"Exception: " << e << endl;
    }
    Pojazd p1 = Pojazd();
    Pojazd p2 = Pojazd("Opel",5000,120.00);
    Pojazd p3 = Pojazd("Kia",2500,1230.00);
    Pojazd p4 = Pojazd("Ford",0,120.00);
    komis.add_pojazd(p1);
    komis.add_pojazd(p2);
    komis.add_pojazd(p3);
    try {
        komis.add_pojazd(p4);
    } catch(std::string e) {
        cout<<"Exception: " << e << endl;
    }
    Komis komis1(komis);

    cout << endl <<"Kontruktor kopiujacy" << endl;
    cout << "Ilosc aut w komis: " << komis.get_licznik() << endl;
    cout << "Ilosc aut w komis1: " << komis1.get_licznik() << endl;

    Komis komis2(std::move(komis));
    cout << endl <<"Kontruktor przenoszacy" << endl;
    cout << "Ilosc aut w komis: " << komis.get_licznik() << endl;
    cout << "Ilosc aut w komis2: " << komis2.get_licznik() << endl;

    komis = Komis();
    komis.add_pojazd(p4);

    komis1 = komis;
    cout << endl << "Kopiowanie" << endl;
    cout << "Ilosc aut w komis: " << komis.get_licznik() << endl;
    cout << "Ilosc aut w komis1: " << komis1.get_licznik() << endl;

    komis1 = std::move(komis);
    cout << endl << "Przenoszenie" << endl;
    cout << "Ilosc aut w komis: " << komis.get_licznik() << endl;
    cout << "Ilosc aut w komis1: " << komis1.get_licznik() << endl;


    Komis *komis_del = new Komis();
    delete komis_del;

    return 0;
}