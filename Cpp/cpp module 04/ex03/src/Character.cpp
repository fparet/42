// ************************************************************************** //
//                                                                            //
//                               Character.cpp                                
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character() : _name("noone") { initSlots_(); }
Character::Character(const std::string& name) : _name(name) { initSlots_(); }

Character::Character(const Character& other) : _name(other._name) {
    initSlots_();
    for (int i = 0; i < 4; ++i) {
        if (other._inv[i]) _inv[i] = other._inv[i]->clone();
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        clearSlots_();
        initSlots_();
        for (int i = 0; i < 4; ++i) {
            if (other._inv[i]) _inv[i] = other._inv[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    clearSlots_();
    // delete floor
    for (int i = 0; i < 128; ++i) {
        if (_floor[i]) { delete _floor[i]; _floor[i] = 0; }
    }
}

void Character::initSlots_() {
    for (int i = 0; i < 4; ++i) _inv[i] = 0;
    for (int i = 0; i < 128; ++i) _floor[i] = 0;
}

void Character::clearSlots_() {
    for (int i = 0; i < 4; ++i) { if (_inv[i]) { delete _inv[i]; _inv[i] = 0; } }
}

const std::string& Character::getName() const { return _name; }

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!_inv[i]) { _inv[i] = m; return; }
    }
    // inventory full -> drop on floor to be cleaned later
    for (int i = 0; i < 128; ++i) {
        if (!_floor[i]) { _floor[i] = m; return; }
    }
    // if floor also full, delete to avoid leak
    delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !_inv[idx]) return;
    // move to floor (do not delete)
    for (int i = 0; i < 128; ++i) {
        if (!_floor[i]) { _floor[i] = _inv[idx]; break; }
    }
    _inv[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !_inv[idx]) return;
    _inv[idx]->use(target);
}
