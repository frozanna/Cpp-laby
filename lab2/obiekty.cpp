#include <iostream>
#include "obiekty.h"

using namespace std;

Wektor1x2::Wektor1x2(float x, float y){
    this->x = x;
    this->y = y;
};

ostream &operator<<(ostream &out, const Wektor1x2 &p){
    return out << "[" << p.x << ", " << p.y << "]" << endl;
}

Wektor1x2 &Wektor1x2::operator-=(const Wektor1x2 &w){
    x -= w.x;
    y -= w.y;
    return (*this);
}


Wektor1x2 Wektor1x2::operator-(const Wektor1x2 &w) const{
    Wektor1x2 tmp;
    tmp.x = x - w.x;
    tmp.y = y - w.y;
    return tmp;
}

Wektor1x2 Wektor1x2::operator*(const Macierz2x2 &m) const{
    Wektor1x2 tmp;
    tmp.x = x*m.mxx + y*m.myx;
    tmp.y = x*m.mxy + y*m.myy;
    return tmp;
}

Wektor1x2 &Wektor1x2::operator++(){
    ++x;
    ++y;
    return (*this);
}

Wektor1x2 Wektor1x2::operator++(int){
    Wektor1x2 tmp(*this);
    ++x;
    ++y;
    return tmp;
}

bool Wektor1x2::operator==(const Wektor1x2 &w) const{
    return (x == w.x) && (y == w.y);
}


float &Wektor1x2::operator[](const int index){
    if(index == 0) return x;
    else if(index == 1)return y;
    cout << "Bledny index." << endl;
    return y;
}


Macierz2x2::Macierz2x2(float mxx, float mxy, float myx, float myy){
    this->mxx = mxx;
    this->mxy = mxy;
    this->myx = myx;
    this->myy = myy;
}

ostream &operator<<(ostream &out, const Macierz2x2 &m){
    return out << "[" << m.mxx << "  " << m.mxy << "]" << endl
               << "[" << m.myx << "  " << m.myy << "]" << endl;
}

Macierz2x2 operator*(const Macierz2x2 &m, const float &f) {
    Macierz2x2 tmp;
    tmp.mxx = m.mxx * f;
    tmp.mxy = m.mxy * f;
    tmp.myx = m.myx * f;
    tmp.myy = m.myy * f;
    return tmp;
}

Macierz2x2 operator*(const float &f, const Macierz2x2 &m) {
    Macierz2x2 tmp = m * f;
    return tmp;
}

Macierz2x2 Macierz2x2::operator-() const{
    Macierz2x2 tmp;
    tmp.mxx = -mxx;
    tmp.mxy = -mxy;
    tmp.myx = -myx;
    tmp.myy = -myy;
    return tmp;
}

Macierz2x2::operator float(){
    return mxx*myy - mxy*myx;
}
