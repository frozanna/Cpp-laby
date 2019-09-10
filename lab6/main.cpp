#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "Animal.h"

using namespace std;


Animal randAnimal(){
    return Animal();
}

void printVec(const vector<Animal> vec){
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << (*it).animalToString() << endl;
    }
}


void increaseAge(Animal &d){
    d.increaseAge(1);
}

bool toRemove(const Animal &d){
    return d.getAge() > 10;
}

bool largerThan(const Animal &d1, const Animal &d2){
    return d1.getAge() < d2.getAge();
}

int main() {

    cout << "--- Vector ---" << endl;

    vector<Animal> animalVec;
    for(int i = 0; i < 15; i++){
        animalVec.push_back(randAnimal());
    }

    printVec(animalVec);

    cout << endl << "--- Set ---" << endl;
    cout << "Duplicates: " << endl;
    set<Animal> animalSet;
    pair<set<Animal>::iterator,bool> ret;

    for(auto it = animalVec.begin(); it != animalVec.end(); it++){
        ret = animalSet.insert(*it);
        if(ret.second == false){
            cout << (*it).animalToString() << endl;
        }
    }

    cout << endl << "Set: " << endl;
    for(auto it = animalSet.begin(); it != animalSet.end(); it++){
        cout << (*it).animalToString() << endl;
    }

    cout << endl << "--- Map ---" << endl;
    map<string, Animal> animalMap;
    for(int i = 0; i < 15; i++){
        Animal d = Animal();
        animalMap.insert(pair<string, Animal>(d.getKey(),d));
    }
    for(auto it = animalMap.begin(); it != animalMap.end(); it++){
        cout << "[" << (*it).first << "] " << (*it).second.animalToString() << endl;
    }


    vector<Animal> animalVec1(15);
    generate(animalVec1.begin(), animalVec1.end(), randAnimal);

    cout << endl << "--- <algorithm> ---"  << endl;
    printVec(animalVec1);

    cout << endl << "max_element: " << max_element(animalVec1.begin(), animalVec1.end(),
                                                   largerThan)->animalToString() << endl;


    string selectedType;
    cout << "Enter species: ";
    cin >> selectedType;
    cout << "count_if " << selectedType << ": " << count_if(animalVec1.begin(), animalVec1.end(), [selectedType](Animal a){return
            a.getSpiecies() == selectedType;}) << endl;

    cout << endl << "for_each: " << endl;
    for_each(animalVec1.begin(), animalVec1.end(), increaseAge);
    printVec(animalVec1);

    cout << endl << "remove_if: " << endl;
    animalVec1.erase(remove_if(animalVec1.begin(), animalVec1.end(), toRemove), animalVec1.end());
    printVec(animalVec1);

    return 0;
}