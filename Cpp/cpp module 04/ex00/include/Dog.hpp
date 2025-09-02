// ************************************************************************** //
//                                                                            //
//                                  Dog.hpp                                   //
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    // Coplien form
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog&);
    virtual ~Dog();

    // Override
    void makeSound() const;
};

#endif // DOG_HPP
