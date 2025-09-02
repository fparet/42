// ************************************************************************** //
//                                                                            //
//                                  Cat.hpp                                   //
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    // Coplien form
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat&);
    virtual ~Cat();

    // Override
    void makeSound() const;
};

#endif // CAT_HPP
