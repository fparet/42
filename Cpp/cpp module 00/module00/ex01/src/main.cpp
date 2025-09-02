// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                    //
//                          42 C++ Module 00 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "PhoneBook.hpp"
#include <iostream>

static std::string prompt(const std::string& msg) {
    std::cout << msg;
    std::string s;
    if (!std::getline(std::cin, s)) return "";
    return s;
}

static Contact read_contact() {
    Contact c;
    c.setFirstName(prompt("First name: "));
    c.setLastName(prompt("Last name: "));
    c.setNickname(prompt("Nickname: "));
    c.setPhoneNumber(prompt("Phone number: "));
    c.setDarkestSecret(prompt("Darkest secret: "));
    return c;
}

int main() {
    PhoneBook pb;
    std::string cmd;
    std::cout << "Welcome to My Awesome PhoneBook. Type ADD, SEARCH or EXIT." << std::endl;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, cmd)) break;
        if (cmd == "EXIT") break;
        else if (cmd == "ADD") {
            Contact c = read_contact();
            if (!c.isEmpty()) {
                pb.addContact(c);
                std::cout << "Contact added." << std::endl;
            } else {
                std::cout << "Empty contact ignored." << std::endl;
            }
        } else if (cmd == "SEARCH") {
            pb.list();
            std::cout << "Enter index (0-7): ";
            std::string s;
            if (!std::getline(std::cin, s)) break;
            if (s.size() != 1 || s[0] < '0' || s[0] > '7') {
                std::cout << "Invalid index." << std::endl;
                continue;
            }
            int idx = s[0] - '0';
            const Contact* c = pb.getContact(idx);
            if (!c) {
                std::cout << "No contact at this index." << std::endl;
            } else {
                std::cout << "First name: " << c->getFirstName() << std::endl;
                std::cout << "Last name : " << c->getLastName() << std::endl;
                std::cout << "Nickname  : " << c->getNickname() << std::endl;
                std::cout << "Phone     : " << c->getPhoneNumber() << std::endl;
                std::cout << "Secret    : " << c->getDarkestSecret() << std::endl;
            }
        } else if (cmd.empty()) {
            continue;
        } else {
            std::cout << "Unknown command. Use ADD, SEARCH or EXIT." << std::endl;
        }
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}
