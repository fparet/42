// ************************************************************************** //
//                                                                            //
//                                AAnimal.cpp                                 //
//                         42 C++ Module 04 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("AAnimal") {
    std::cout << "AAnimal default-constructed" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type) {
    std::cout << "AAnimal constructed with type: " << _type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
    std::cout << "AAnimal copy-constructed" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) _type = other._type;
    std::cout << "AAnimal copy-assigned" << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destroyed" << std::endl;
}

const std::string& AAnimal::getType() const {
    return _type;
}
