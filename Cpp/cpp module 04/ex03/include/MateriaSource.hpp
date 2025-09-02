// ************************************************************************** //
//                                                                            //
//                            MateriaSource.hpp                                
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
    // Coplien
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource&);
    virtual ~MateriaSource();

    // IMateriaSource
    void learnMateria(AMateria*);
    AMateria* createMateria(const std::string& type);

private:
    AMateria* _slots[4];
    void init_();
    void clear_();
};

#endif // MATERIASOURCE_HPP
