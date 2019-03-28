#include <iostream>
#include "obiekty.h"

using namespace std;

int main() {
    Macierz2x2 m1;
    Wektor1x2 w1,w2,w3;
    m1 = Macierz2x2(6,2,3,4);
    w1 = Wektor1x2(4,5);
    w2 = Wektor1x2(2,1);
    w3 = Wektor1x2();
    cout << endl << "m1: " << endl;
    cout << m1;
    cout << "w1: " << endl;
    cout << w1;
    cout << "w2: " << endl;
    cout << w2;
    cout << "w3: " << endl;
    cout << w3;
    cout << "-----------------" << endl;


    cout << "w1 - w2: " << endl;
    cout << (w1 - w2) << endl << endl;
    cout << "w1 -= w2: " << endl;
    w1 -= w2;
    cout << w1 << endl << endl;


    float f = 2.0;
    cout << "m1 * 2.0: " << endl;
    cout << (m1 * f) << endl << endl;

    cout << "2.0 * m1: " << endl;
    cout << (f * m1) << endl << endl;

    cout << "w1 * m1: " << endl;
    cout << (w1 * m1) << endl << endl;

    w1++;
    ++w2;
    cout << "w1++: " << endl;
    cout << w1 << endl << endl;
    cout << "++w2: " << endl;
    cout << w2 << endl << endl;

    cout << "-m1: " << endl;
    cout << -m1 << endl << endl;

    w3 = Wektor1x2(3,5);
    if(w1 == w2) cout << "w1 == w2" << endl;
    else cout << "w1 != w2" << endl;
    if(w1 == w3) cout << "w1 == w3" << endl;
    else cout << "w1 != w3" << endl;

    cout << endl << "w1: " << w1;
    cout << "w1[0] => " << w1[0] << endl;
    cout << "w1[1] => " << w1[1] << endl;
    cout << endl;


    cout << "Wyznacznik m1: " << (float)m1 << endl;

    return 0;
}