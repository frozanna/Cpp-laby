#include <iostream>
#include <sstream>

using namespace std;

class Data{
    int d;
    int m;
    int r;
    static int lata;

public:
    Data();
    Data(int d, int m, int r = 2000);
    int getYear(){ return r; }
    void addYear(){ r++; }
    bool isEarlier(Data givenData);
    void printData();
    static int getLata(){ return lata; }
    friend ostream &operator<<(ostream &out, const Data &d);
    friend istream &operator>>(istream  &in, Data &d);
};

Data::Data(){
    this->d = 1;
    this->m = 1;
    this->r = 2000;
    lata++;
}

Data::Data(int d, int m, int r){
    if(m < 1 || m > 12 || d > 31 || d < 1 || r < 0){
        this->d = 1;
        this->m = 1;
        this->r = 2000;
    }else{
        this->d = d;
        this->m = m;
        this->r = r;
    }
    lata++;
}

void Data::printData(){
    if(d < 10){
        cout << "0" << d << ".";
    } else{
        cout << d << ".";
    }
    if(d < 10){
        cout << "0" << m << ".";
    } else{
        cout << m << ".";
    }
    cout << r;
}

bool Data::isEarlier(Data givenData){
    if(r < givenData.r) return true;
    else if(r == givenData.r){
        if(m < givenData.m) return true;
        else if(m == givenData.m){
            if(d < givenData.d) return true;
        }
    }
    return false;
}

ostream &operator<< (ostream &out, const Data &d){
    if(d.d < 10){
        if(d.m < 10){
            return out << d.r << "-0" << d.m << "-0" << d.d;
        } else{
            return out << d.r << "-" << d.m << "-0" << d.d;
        }
    } else{
        if(d.m < 10){
            return out << d.r << "-0" << d.m << "-" << d.d;
        } else{
            return out << d.r << "-" << d.m << "-" << d.d;
        }
    }
}

istream &operator>>(istream  &in, Data &d){
    string line;
    getline(in, line);
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '-') line[i] = ' ';
    }
    istringstream iss(line);
    iss >> d.r >> d.m >> d.d;
    return in;
}

int Data::lata = 0;

int main() {
    Data dat = Data();
    Data dat2;
    cout << dat << endl;
    cin >> dat2;
    cout << dat2 << endl;
    dat2.addYear();
    cout << dat2.getYear() << endl;
    cout << dat.isEarlier(dat2) << endl;
    cout << "Lata: " << Data::getLata();
    return 0;
}