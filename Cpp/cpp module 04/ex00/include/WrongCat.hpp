// ************************************************************************** //
//                                                                            //
//                               WrongCat.hpp                                 
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    // Coplien form
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat&);
    ~WrongCat();

    // "Override" (but base method is non-virtual, so slicing occurs)
    void makeSound() const;
};

#endif // WRONGCAT_HPP
