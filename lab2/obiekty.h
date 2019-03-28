#ifndef OBIEKTY
#define OBIEKTY

class Wektor1x2;
class Macierz2x2;

class Wektor1x2{
    float x;
    float y;

public:
    Wektor1x2(float x = 0, float y = 0);
    friend std::ostream &operator<<(std::ostream &out, const Wektor1x2 &d);
    Wektor1x2 &operator-=(const Wektor1x2 &w);
    Wektor1x2 operator-(const Wektor1x2 &w) const;
    Wektor1x2 operator*(const Macierz2x2 &m) const;
    Wektor1x2 &operator++();
    Wektor1x2 operator++(int);
    bool operator==(const Wektor1x2 &w) const;
    float &operator[](const int index);
};

class Macierz2x2{
    float mxx;
    float mxy;
    float myx;
    float myy;

public:
    Macierz2x2(float mxx = 0, float mxy = 0, float myx = 0, float myy = 0);
    friend std::ostream &operator<<(std::ostream &out, const Macierz2x2 &m);
    friend Macierz2x2 operator*(const Macierz2x2 &m, const float &f) ;
    friend Macierz2x2 operator*(const float &f, const Macierz2x2 &m);
    friend Wektor1x2 Wektor1x2::operator*(const Macierz2x2 &m) const;
    Macierz2x2 operator-() const;
    operator float();
};

#endif //OBIEKTY
