#include "Animal.h"

using namespace std;

bool Animal::operator<(const Animal &d) const{
    return this->getKey() < d.getKey();
}

bool Animal::operator==(const Animal &d) const{
    return this->getKey() == d.getKey();
}

std::string Animal::getKey() const {
    return species + name;
}

std::string Animal::animalToString() const {
    return species + ", " + name + ", age: " + to_string(age);
}