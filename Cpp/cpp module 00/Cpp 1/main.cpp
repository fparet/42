// main.cpp
#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook pb;
    std::string command;

    std::cout << "Welcome to the PhoneBook!" << std::endl;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof()) break;

        if (command == "ADD") {
            pb.addContact();
        } else if (command == "SEARCH") {
            pb.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
