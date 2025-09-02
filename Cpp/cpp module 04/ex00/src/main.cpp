// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << "\n==== " << title << " ====" << std::endl;
}

int main() {
    separator("Polymorphism (correct)");
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    meta->makeSound(); // generic
    dog->makeSound();  // woof
    cat->makeSound();  // meow
    delete meta;
    delete dog;
    delete cat;

    separator("Polymorphism (wrong base, no virtual)");
    const WrongAnimal* w = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    std::cout << wc->getType() << " " << std::endl;
    w->makeSound();    // generic wrong
    wc->makeSound();   // still generic wrong (not virtual)
    delete w;
    delete wc;

    return 0;
}
