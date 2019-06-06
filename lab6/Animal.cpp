#include "Animal.h"

using namespace std;

bool Animal::operator<(const Animal &d) const{
    return this->get_key() < d.get_key();
}

bool Animal::operator==(const Animal &d) const{
    return this->get_key() == d.get_key();
}

std::string Animal::get_key() const {
    return species + name;
}

std::string Animal::animal_to_string() const {
    return species + ", " + name + ", age: " + to_string(age);
}