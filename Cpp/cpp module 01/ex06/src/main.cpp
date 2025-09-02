// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 01 - ex06                            //
//                                                                            //
// ************************************************************************** //
#include "Harl.hpp"
#include <iostream>

static int level_index(const std::string &level) {
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <DEBUG|INFO|WARNING|ERROR>" << std::endl;
        return 1;
    }
    Harl harl;
    int idx = level_index(argv[1]);
    switch (idx) {
        case 0: // DEBUG
            harl.complain("DEBUG");
            std::cout << std::endl;
        case 1: // INFO
            harl.complain("INFO");
            std::cout << std::endl;
        case 2: // WARNING
            harl.complain("WARNING");
            std::cout << std::endl;
        case 3: // ERROR
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}
