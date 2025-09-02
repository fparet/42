// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 04 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << "\n==== " << title << " ====" << std::endl;
}

int main() {
    separator("Abstract class usage");
    // AAnimal a; // <-- interdit: classe abstraite (décommentez pour vérifier la compilation échoue)

    const int N = 4;
    AAnimal* zoo[N];
    for (int i = 0; i < N; ++i) {
        if (i % 2) zoo[i] = new Cat();
        else       zoo[i] = new Dog();
    }
    for (int i = 0; i < N; ++i) {
        std::cout << zoo[i]->getType() << " → ";
        zoo[i]->makeSound();
    }
    for (int i = 0; i < N; ++i) delete zoo[i];

    separator("Deep copy checks");
    Dog d1;
    d1.getBrain()->setIdea(0, "Catch the ball");
    Dog d2 = d1;
    d2.getBrain()->setIdea(0, "Guard the yard");
    std::cout << "d1 idea[0]: " << d1.getBrain()->getIdea(0) << std::endl;
    std::cout << "d2 idea[0]: " << d2.getBrain()->getIdea(0) << std::endl;

    Cat c1;
    c1.getBrain()->setIdea(1, "Nap on keyboard");
    Cat c2;
    c2 = c1;
    c2.getBrain()->setIdea(1, "Knock over glass");
    std::cout << "c1 idea[1]: " << c1.getBrain()->getIdea(1) << std::endl;
    std::cout << "c2 idea[1]: " << c2.getBrain()->getIdea(1) << std::endl;

    return 0;
}
