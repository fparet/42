// ************************************************************************** //
//                                                                            //
//                                  Cat.hpp                                   //
//                         42 C++ Module 04 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
public:
    // Coplien form
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat&);
    virtual ~Cat();

    // Override
    void makeSound() const;

    // Brain access
    Brain* getBrain() const;

private:
    Brain* _brain;
};

#endif // CAT_HPP
