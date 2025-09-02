// ************************************************************************** //
//                                                                            //
//                               Contact.cpp                                   //
//                          42 C++ Module 00 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Contact.hpp"

Contact::Contact() {}
Contact::Contact(const Contact& other) { *this = other; }
Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        _firstName = other._firstName;
        _lastName = other._lastName;
        _nickname = other._nickname;
        _phoneNumber = other._phoneNumber;
        _darkestSecret = other._darkestSecret;
    }
    return *this;
}
Contact::~Contact() {}

void Contact::setFirstName(const std::string& s) { _firstName = s; }
void Contact::setLastName(const std::string& s) { _lastName = s; }
void Contact::setNickname(const std::string& s) { _nickname = s; }
void Contact::setPhoneNumber(const std::string& s) { _phoneNumber = s; }
void Contact::setDarkestSecret(const std::string& s) { _darkestSecret = s; }

const std::string& Contact::getFirstName() const { return _firstName; }
const std::string& Contact::getLastName() const { return _lastName; }
const std::string& Contact::getNickname() const { return _nickname; }
const std::string& Contact::getPhoneNumber() const { return _phoneNumber; }
const std::string& Contact::getDarkestSecret() const { return _darkestSecret; }

bool Contact::isEmpty() const {
    return _firstName.empty() && _lastName.empty() && _nickname.empty()
        && _phoneNumber.empty() && _darkestSecret.empty();
}
