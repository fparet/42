// ************************************************************************** //
//                                                                            //
//                              PhoneBook.cpp                                  //
//                          42 C++ Module 00 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _size(0), _nextIndex(0) {}
PhoneBook::PhoneBook(const PhoneBook& other) { *this = other; }
PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) _contacts[i] = other._contacts[i];
        _size = other._size;
        _nextIndex = other._nextIndex;
    }
    return *this;
}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& c) {
    _contacts[_nextIndex] = c;
    _nextIndex = (_nextIndex + 1) % 8;
    if (_size < 8) ++_size;
}

const Contact* PhoneBook::getContact(int idx) const {
    if (idx < 0 || idx >= _size) return 0;
    return &_contacts[idx];
}

std::string PhoneBook::formatField(const std::string& s) {
    if (s.size() > 10) return s.substr(0, 9) + ".";
    std::string out = s;
    if (out.size() < 10) out = std::string(10 - out.size(), ' ') + out;
    return out;
}

void PhoneBook::list() const {
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|      Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    for (int i = 0; i < _size; ++i) {
        std::cout << "|" << formatField(std::string(i < 10 ? (1, '0') : 0, ' ') + (std::string() + char('0'+i)))
                  << "|" << formatField(_contacts[i].getFirstName())
                  << "|" << formatField(_contacts[i].getLastName())
                  << "|" << formatField(_contacts[i].getNickname()) << "|" << std::endl;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
}
