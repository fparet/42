// ************************************************************************** //
//                                                                            //
//                             WrongAnimal.cpp                                
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal default-constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
    std::cout << "WrongAnimal constructed with type: " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "WrongAnimal copy-constructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) _type = other._type;
    std::cout << "WrongAnimal copy-assigned" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "*generic wrong animal sound*" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return _type;
}
