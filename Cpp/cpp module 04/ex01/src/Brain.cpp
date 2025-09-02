// ************************************************************************** //
//                                                                            //
//                                Brain.cpp                                   //
//                         42 C++ Module 04 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain default-constructed" << std::endl;
    for (int i = 0; i < 100; ++i) _ideas[i] = "";
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy-constructed" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy-assigned" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

const std::string& Brain::getIdea(int idx) const {
    static const std::string empty = "";
    if (idx < 0 || idx >= 100) return empty;
    return _ideas[idx];
}

void Brain::setIdea(int idx, const std::string& idea) {
    if (idx < 0 || idx >= 100) return;
    _ideas[idx] = idea;
}
