#include <iostream>
#include <cstring>
#include "List.h"
using namespace std;


template <class T>
bool equals(T a, T b, T c){
    return a == b && a == c;
}

template<>
bool equals<const char*>(const char *a, const char *b, const char *c){
    return strcmp(a,b) == 0 && strcmp(a, c) == 0;
}



int main() {

    cout << "equals(1,1,1) = " << equals(1,1,1) << endl;
    cout << "equals(1.1,1.1,1.1) = " << equals(1.1,1.1,1.1) << endl;
    cout << "equals(1,1,2) = " << equals(1,1,2) << endl;
    cout << "equals(\"ala\", \"ala\", \"ala\") = " << equals("ala", "ala", "ala") << endl;
    cout << "equals(\"ala\", \"a\", \"a\") = " << equals("ala", "a", "a") << endl;

    cout << endl;


    LinkList<int> list;
    cout << list;
    list.add(1,0);
    list.add(2,1);
    list.add(3,2);
    list.add(4,1);
    list.add(5,4);
    list.add(6,0);
    cout << list << endl;

    try{
        list.add(10,100);
    }catch(ListException &e){
        cout << e.what() << endl;
    }


    try{
        LinkList<int> emptyList;
        list.add(10,10);
    }catch(ListException &e){
        cout << e.what() << endl;
    }



    return 0;
}