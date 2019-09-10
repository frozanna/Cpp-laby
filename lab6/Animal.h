#include <iostream>

#ifndef CPP6_H
#define CPP6_H

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
    std::string getKey() const;
    std::string getSpiecies() const { return species; };
    std::string getName() const { return name; };
    int getAge() const { return age; };
    std::string animalToString() const;
    void increaseAge(int i) { age += i; };

};



#endif //CPP6_H
