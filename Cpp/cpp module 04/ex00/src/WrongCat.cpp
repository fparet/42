// ************************************************************************** //
//                                                                            //
//                                WrongCat.cpp                                
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy-constructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    std::cout << "WrongCat copy-assigned" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow??? (but you'll never hear this via WrongAnimal*)" << std::endl;
}
