// ************************************************************************** //
//                                                                            //
//                                Animal.cpp                                  //
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal") {
    std::cout << "Animal default-constructed" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type) {
    std::cout << "Animal constructed with type: " << _type << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << "Animal copy-constructed" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) _type = other._type;
    std::cout << "Animal copy-assigned" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "*generic animal sound*" << std::endl;
}

const std::string& Animal::getType() const {
    return _type;
}
