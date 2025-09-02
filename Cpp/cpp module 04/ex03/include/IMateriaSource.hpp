// ************************************************************************** //
//                                                                            //
//                            IMateriaSource.hpp                               
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}

    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif // IMATERIASOURCE_HPP
