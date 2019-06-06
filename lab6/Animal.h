#include <iostream>

#ifndef CPP6_DRZEWO_H
#define CPP6_DRZEWO_H

class Animal{
    std::string species;
    std::string name;
    int age;
public:
    Animal(std::string _species, std::string _name, int _age): species(_species), name(_name), age(_age) {};
    Animal(){
        std::string species_[] = {"Kot", "Pies", "Chomik"};
        std::string names[] = {"Puszek", "Reksio", "Chmurek"};
        species = species_[rand()%3];
        name = names[rand()%3];
        age = rand()%20 + 1;
    }

    bool operator<(const Animal &d) const;
    bool operator==(const Animal &d) const;
    std::string get_key() const;
    std::string get_spiecies() const { return species; };
    std::string get_name() const { return name; };
    int get_age() const { return age; };
    std::string animal_to_string() const;
    void increase_age(int i) { age += i; };

};



#endif //CPP6_DRZEWO_H
