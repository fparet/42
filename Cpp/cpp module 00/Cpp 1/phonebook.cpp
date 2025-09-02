// PhoneBook.cpp
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    totalContacts = 0;
}

void PhoneBook::addContact() {
    std::string fn, ln, nn, pn, ds;

    std::cout << "First Name: ";
    std::getline(std::cin, fn);
    std::cout << "Last Name: ";
    std::getline(std::cin, ln);
    std::cout << "Nickname: ";
    std::getline(std::cin, nn);
    std::cout << "Phone Number: ";
    std::getline(std::cin, pn);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, ds);

    int index = totalContacts % 8;
    contacts[index].setInfo(fn, ln, nn, pn, ds);
    totalContacts++;
    std::cout << "✅ Contact added!" << std::endl;
}

void PhoneBook::searchContact() const {
    if (totalContacts == 0) {
        std::cout << "No contacts yet." << std::endl;
        return;
    }

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < (totalContacts < 8 ? totalContacts : 8); i++) {
        contacts[i].displayShort(i);
    }

    std::cout << "Enter index: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
        int index = input[0] - '0';
        if (index < (totalContacts < 8 ? totalContacts : 8))
            contacts[index].displayFull();
        else
            std::cout << "Invalid index." << std::endl;
    } else {
        std::cout << "Invalid input." << std::endl;
    }
}
