// Contact.cpp
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

void Contact::setInfo(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) {
    firstName = fn;
    lastName = ln;
    nickname = nn;
    phoneNumber = pn;
    darkestSecret = ds;
}

void Contact::displayShort(int index) const {
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName);
    std::cout << "|" << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName);
    std::cout << "|" << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname);
    std::cout << "|" << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First Name:     " << firstName << std::endl;
    std::cout << "Last Name:      " << lastName << std::endl;
    std::cout << "Nickname:       " << nickname << std::endl;
    std::cout << "Phone Number:   " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
