#include <iostream>
#include "Prostokat.h"
#include "Kwadrat.h"
#include "Kolo.h"
#include "Punkt.h"

using namespace std;
using namespace lab4;

int main() {
    Punkt p(10,30);
    cout << p << endl;
    p.setX(15);
    p.zapisz(cout);
    cout << endl;
    p.wczytaj(cin);
    cout << "Nowe X: " << p.getX() << endl << endl;

    Figura *f[3];
    f[0] = new Kolo(Punkt(10,5),"Kolo1",15);
    f[1] = new Prostokat(Punkt(4,8),"Prostokat1",10,5);
    f[2] = new Kwadrat(Punkt(2,4),"Kwadrat1",6);

    f[0]->zapisz(cout);
    cout << endl;
    f[0]->wczytaj(cin);

    cout << f[0]->opis() << " | pole: " << f[0]->pole() << endl << endl;

    f[1]->zapisz(cout);
    cout << endl;
    f[1]->wczytaj(cin);

    cout << f[1]->opis() << " | pole: " << f[1]->pole() << endl << endl;

    f[2]->zapisz(cout);
    cout << endl;
    f[2]->wczytaj(cin);

    cout << f[2]->opis() << " | pole: " << f[2]->pole() << endl << endl;

    f[2]->przesun(Punkt(1,2));
    cout << endl << f[2]->opis();


    cout << endl << endl << endl;

    delete f[0];
    delete f[1];
    delete f[2];

    return 0;
}