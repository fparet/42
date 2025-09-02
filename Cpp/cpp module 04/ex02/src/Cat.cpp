// ************************************************************************** //
//                                                                            //
//                                  Cat.cpp                                   //
//                         42 C++ Module 04 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
    std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Cat copy-constructed (deep copy)" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        if (_brain) delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Cat copy-assigned (deep copy)" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}
