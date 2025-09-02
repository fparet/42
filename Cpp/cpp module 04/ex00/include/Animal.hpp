// ************************************************************************** //
//                                                                            //
//                                Animal.hpp                                  //
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
    // Coplien form
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal&);
    virtual ~Animal();

    // Custom
    explicit Animal(const std::string& type);

    // Polymorphic interface
    virtual void makeSound() const;
    const std::string& getType() const;

protected:
    std::string _type;
};

#endif // ANIMAL_HPP
