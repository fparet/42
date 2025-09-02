// ************************************************************************** //
//                                                                            //
//                            MateriaSource.cpp                               
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() { init_(); }
MateriaSource::MateriaSource(const MateriaSource& other) { init_(); *this = other; }
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        clear_();
        for (int i = 0; i < 4; ++i) {
            if (other._slots[i]) _slots[i] = other._slots[i]->clone();
        }
    }
    return *this;
}
MateriaSource::~MateriaSource() { clear_(); }

void MateriaSource::init_() { for (int i=0;i<4;++i) _slots[i]=0; }
void MateriaSource::clear_() { for (int i=0;i<4;++i) { if (_slots[i]) { delete _slots[i]; _slots[i]=0; } } }

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!_slots[i]) { _slots[i] = m; return; }
    }
    // full -> delete incoming to avoid leak
    delete m;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; ++i) {
        if (_slots[i] && _slots[i]->getType() == type) return _slots[i]->clone();
    }
    return 0;
}
