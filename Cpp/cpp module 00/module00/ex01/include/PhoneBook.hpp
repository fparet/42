// ************************************************************************** //
//                                                                            //
//                              PhoneBook.hpp                                  //
//                          42 C++ Module 00 - ex01                            //
//                                                                            //
// ************************************************************************** //
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
public:
    // Coplien
    PhoneBook();
    PhoneBook(const PhoneBook& other);
    PhoneBook& operator=(const PhoneBook&);
    ~PhoneBook();

    void addContact(const Contact& c);
    const Contact* getContact(int idx) const; // 0..7 or NULL
    void list() const;

private:
    Contact _contacts[8];
    int     _size;
    int     _nextIndex;

    static std::string formatField(const std::string& s);
};

#endif // PHONEBOOK_HPP
