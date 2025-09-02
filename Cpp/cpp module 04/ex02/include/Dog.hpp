// ************************************************************************** //
//                                                                            //
//                                  Dog.hpp                                   //
//                         42 C++ Module 04 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
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
