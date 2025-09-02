// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 04 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << "\n==== " << title << " ====" << std::endl;
}

int main() {
    separator("Array of Animals with polymorphism");
    const int N = 4;
    Animal* zoo[N];
    for (int i = 0; i < N; ++i) {
        if (i % 2) zoo[i] = new Cat();
        else       zoo[i] = new Dog();
    }
    for (int i = 0; i < N; ++i) zoo[i]->makeSound();
    for (int i = 0; i < N; ++i) delete zoo[i];

    separator("Deep copy check (Dog)");
    Dog d1;
    d1.getBrain()->setIdea(0, "Chase the cat");
    Dog d2 = d1; // copy ctor (deep)
    d2.getBrain()->setIdea(0, "Guard the house");
    std::cout << "d1 idea[0]: " << d1.getBrain()->getIdea(0) << std::endl;
    std::cout << "d2 idea[0]: " << d2.getBrain()->getIdea(0) << std::endl;

    separator("Deep copy check (Cat via assignment)");
    Cat c1;
    c1.getBrain()->setIdea(1, "Rule the world");
    Cat c2;
    c2 = c1; // operator= deep copy
    c2.getBrain()->setIdea(1, "Sleep 20 hours");
    std::cout << "c1 idea[1]: " << c1.getBrain()->getIdea(1) << std::endl;
    std::cout << "c2 idea[1]: " << c2.getBrain()->getIdea(1) << std::endl;

    return 0;
}
