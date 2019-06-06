#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "Animal.h"

using namespace std;


Animal rand_animal(){
    return Animal();
}

void print_vec(const vector<Animal> vec){
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << (*it).animal_to_string() << endl;
    }
}


void increase_age(Animal &d){
    d.increase_age(1);
}

bool to_remove(const Animal &d){
    return d.get_age() > 10;
}

bool larger_than(const Animal &d1,const Animal &d2){
    return d1.get_age() < d2.get_age();
}

int main() {


    cout << "--- Vector ---" << endl;

    vector<Animal> animal_vec;
    for(int i = 0; i < 15; i++){
        animal_vec.push_back(rand_animal());
    }

    print_vec(animal_vec);

    cout << endl << "--- Set ---" << endl;
    cout << "Duplicates: " << endl;
    set<Animal> animal_set;
    pair<set<Animal>::iterator,bool> ret;

    for(auto it = animal_vec.begin(); it != animal_vec.end(); it++){
        ret = animal_set.insert(*it);
        if(ret.second == false){
            cout << (*it).animal_to_string() << endl;
        }
    }

    cout << endl << "Set: " << endl;
    for(auto it = animal_set.begin(); it != animal_set.end(); it++){
        cout << (*it).animal_to_string() << endl;
    }

    cout << endl << "--- Map ---" << endl;
    map<string, Animal> animal_map;
    for(int i = 0; i < 15; i++){
        Animal d = Animal();
        animal_map.insert(pair<string, Animal>(d.get_key(),d));
    }
    for(auto it = animal_map.begin(); it != animal_map.end(); it++){
        cout << "[" << (*it).first << "] " << (*it).second.animal_to_string() << endl;
    }


    vector<Animal> animal_vec1(15);
    generate(animal_vec1.begin(), animal_vec1.end(), rand_animal);

    cout << endl << "--- <algorithm> ---"  << endl;
    print_vec(animal_vec1);

    cout << endl << "max_element: " << max_element(animal_vec1.begin(), animal_vec1.end(), larger_than)->animal_to_string() << endl;


    string selected_type;
    cout << "Enter species: ";
    cin >> selected_type;
    cout << "count_if " << selected_type << ": " << count_if(animal_vec1.begin(), animal_vec1.end(), [selected_type](Animal a){return a.get_spiecies() == selected_type;}) << endl;

    cout << endl << "for_each: " << endl;
    for_each(animal_vec1.begin(), animal_vec1.end(), increase_age);
    print_vec(animal_vec1);

    cout << endl << "remove_if: " << endl;
    animal_vec1.erase(remove_if(animal_vec1.begin(), animal_vec1.end(), to_remove), animal_vec1.end());
    print_vec(animal_vec1);

    return 0;
}