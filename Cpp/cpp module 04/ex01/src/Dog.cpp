// ************************************************************************** //
//                                                                            //
//                                  Dog.cpp                                   //
//                         42 C++ Module 04 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
    std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Dog copy-constructed (deep copy)" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        // Deep copy
        if (_brain) delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Dog copy-assigned (deep copy)" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}
