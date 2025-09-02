// ************************************************************************** //
//                                                                            //
//                                  Dog.hpp                                   //
//                         42 C++ Module 04 - ex01                            //
//                                                                            //
// ************************************************************************** //
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
    // Coplien form
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog&);
    virtual ~Dog();

    // Override
    void makeSound() const;

    // Brain access
    Brain* getBrain() const;

private:
    Brain* _brain;
};

#endif // DOG_HPP
