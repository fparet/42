// ************************************************************************** //
//                                                                            //
//                                 Cure.hpp                                   
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
    // Coplien
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure&);
    virtual ~Cure();

    // AMateria
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif // CURE_HPP
